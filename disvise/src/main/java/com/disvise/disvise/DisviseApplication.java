package com.disvise.disvise;

import ch.qos.logback.core.net.SyslogOutputStream;
import com.disvise.disvise.advise.Advise;
import com.disvise.disvise.advise.AdviseToControler;
import com.disvise.disvise.advise.BbddControler;
import com.disvise.disvise.advise.varGlobales;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.amqp.rabbit.core.RabbitTemplate;

import java.time.LocalDate;
import java.time.Month;
import java.util.List;

@SpringBootApplication
@RestController //Necesario para poder consumir o consultar informacion desde este fichero
public class DisviseApplication {


	public static void main(String[] args) {
		SpringApplication.run(DisviseApplication.class, args);
	}

	//Necesitamos almacenar una lista de elementos:
	//Entero que indique la prioridad, a igualdad de prioridad seguirá un FIFO
	//Magic Number encargado de filtrar si la petición ha sido realizada desde este programa (Seguridad)
	//Un entero encargado de decir qué funcion del microcontrolador se va a realizar (que muestra por pantalla)
	//La hora local
	//Un id que almacenará a qué cola de RabbitMQ enviará la información (elemento no guardable en la lista pero muy útil)

	//La lista de todas las peticiones se gestionarán por RabbitMQ

	@Autowired
	private RabbitTemplate rabbitTemplate;

	@Autowired
	private BbddControler adviseRepository;

	//al microcontrolador y este se va a encargar de consumirlos
	@GetMapping(path = "/{priority}/{magicNumber}/{function}/{destiny}") //mapeamos para que esta funcion se pueda consultar desde el navegador (solo usado para debuggear)
	public String avisos(@PathVariable int priority, @PathVariable Long magicNumber,
						 @PathVariable int function, @PathVariable String destiny){
		if(magicNumber == 123456L && priority < varGlobales.prioridades){
			AdviseToControler adviseToSend = new AdviseToControler(function);
			String newDestiny = destiny + "p" + priority;
			rabbitTemplate.convertAndSend(newDestiny, adviseToSend); //Mensaje en JSON

			//Insertar en la bbdd
			Advise advise = new Advise(priority, magicNumber, adviseToSend, LocalDate.now(), destiny);
			adviseRepository.insertarAdvise(advise);
			//Crear peticion para el microcontrolador y enconlar
			return "Numero correcto, peticion encolada en " + destiny;
		}else{
			return "Error, credenciales incorrectas";
		}
	}

	@GetMapping(path = "/{id_cola}")
	public AdviseToControler desencolar(@PathVariable String id_cola){
		AdviseToControler result = new AdviseToControler(-1);
		//Bucle registrando las colas de prioridades
		String newIdCola = "";
		int i = 0;
		Object mensaje = null;
		while (mensaje == null && i < varGlobales.prioridades){
			newIdCola = id_cola + "p" + i;
			mensaje = rabbitTemplate.receiveAndConvert(newIdCola);
			i++;
		}
		if (mensaje instanceof AdviseToControler) {
			return (AdviseToControler) mensaje;
		}
		// Si no hay mensaje o no es del tipo esperado, devolver valor por defecto
		return new AdviseToControler(-1);
	}

	@GetMapping(path = "/{function}/{id_cola}")
	public int ControlerToControler(@PathVariable int function ,@PathVariable String id_cola){
		for (int i = 0; i < varGlobales.listaGlobal.size(); i++){
			System.out.println(varGlobales.listaGlobal.get(i));
		}
		boolean eliminado = varGlobales.listaGlobal.remove(id_cola);

		// Si la lista está vacía (solo hay un dispositivo conectado a la api)
		if (varGlobales.listaGlobal.isEmpty()) {
			// Volver a añadir el propio antes de salir
			if (eliminado) varGlobales.listaGlobal.add(id_cola);
			AdviseToControler adviseToSend = new AdviseToControler(function);
			String newDestiny = id_cola + "p" + 0;//al ser el unico dispositivo es muy importante que acepte el aviso
			rabbitTemplate.convertAndSend(newDestiny, adviseToSend);
			return -1;
		}
		// Obtener el primer distinto (ya no está en la lista)
		String nextControler = varGlobales.listaGlobal.get(0);
		AdviseToControler adviseToSend = new AdviseToControler(function);
		String newDestiny = "";
		if(varGlobales.prioridades > 1){
			newDestiny = nextControler + "p" + 1;
		}else{
			newDestiny = nextControler + "p" + 0;
		}
		rabbitTemplate.convertAndSend(newDestiny, adviseToSend);

		// Encolando el elemento nuevamente pasa a estar como ocupado y sera el ultimo en recibir peticion
		if (eliminado) varGlobales.listaGlobal.add(id_cola);

		return 1;
	}

	//Funcion auxiliar para ver la bbdd:
	@GetMapping("/datos")
	public List<Advise> obtenerDatos() {
		return adviseRepository.obtenerTodos();
	}
}
