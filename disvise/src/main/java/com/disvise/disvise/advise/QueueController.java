package com.disvise.disvise.advise;

import com.disvise.disvise.advise.varGlobales;
import ch.qos.logback.core.net.SyslogOutputStream;
import org.springframework.amqp.core.Queue;
import org.springframework.amqp.rabbit.core.RabbitAdmin;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/colas")
public class QueueController {
    private final RabbitMQFunctions rabbitMQFunctions;

    @Autowired
    public QueueController(RabbitMQFunctions rabbitMQFunctions) {
        this.rabbitMQFunctions = rabbitMQFunctions;
    }

    // POST /colas/crear?id=dispositivo123
    //@PostMapping("/crear") post para cuando podamos poner un form en algun boton o algo asi
    @GetMapping("/crear")
    public String crearCola(@RequestParam String id) {
        varGlobales.listaGlobal.add(id);
        String queueName = "";
        for(int i = 0; i < varGlobales.prioridades; i++){
            queueName = id+"p"+i;
            rabbitMQFunctions.crearCola(queueName);
        }
        return "Colas creadas ";
    }

    // DELETE /colas/destruir/dispositivo123
    //@DeleteMapping("/destruir/{id}") //Igual que con post
    @GetMapping("/destruir/{id}")
    public String destruirCola(@PathVariable String id) {
        boolean eliminado = false;
        String queueName = "";
        for (int i = 0; i < varGlobales.prioridades; i ++){
            queueName = id + "p" +i;
            eliminado =  rabbitMQFunctions.eliminarCola(queueName);
        }

        if(eliminado){
            varGlobales.listaGlobal.remove(id);
            return "Colas eliminadas";
        }else{
            return "No se pudo eliminar alguna cola, conctacte a soporte";
        }
    }
}
