package com.disvise.disvise.advise;

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
    @GetMapping("/Crear")
    public String crearCola(@RequestParam String id) {
        String queueName = "cola_" + id;
        rabbitMQFunctions.crearCola(queueName);
        return "Cola creada: " + queueName;
    }

    // DELETE /colas/destruir/dispositivo123
    @DeleteMapping("/destruir/{id}")
    public String destruirCola(@PathVariable String id) {
        String queueName = "cola_" + id;
        boolean eliminado =  rabbitMQFunctions.eliminarCola(queueName);
        if(eliminado){
            return "Cola eliminada: " + queueName;
        }else{
            return "No se pudo eliminar: " + queueName;
        }
    }
}
