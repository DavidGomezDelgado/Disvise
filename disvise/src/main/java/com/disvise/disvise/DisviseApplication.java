package com.disvise.disvise;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

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
	//Un entero encargado de decir qué funcion del microcontrolador se va a realizar
	//Otro entero que indica un lugar, esto va a usar para saber que icono mostrar en la pantalla
	//La hora local
	//Un id que almacenará a qué cola de RabbitMQ enviará la información (elemento no guardable en la lista pero muy útil)

	//La lista de todas las peticiones se gestionarán por RabbitMQ


	//al microcontrolador y este se va a encargar de consumirlos
	@GetMapping(path = "/") //mapeamos para que esta funcion se pueda consultar desde el navegador (solo usado para debuggear)
	public List<Integer> avisos(){
		return List.of(1,2,3,4);
	}
}
