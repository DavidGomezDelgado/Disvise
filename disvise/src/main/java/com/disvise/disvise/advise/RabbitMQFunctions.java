package com.disvise.disvise.advise;

import org.springframework.amqp.core.AmqpAdmin;
import org.springframework.amqp.core.Queue;
import org.springframework.stereotype.Component;


@Component
public class RabbitMQFunctions {

    private final AmqpAdmin amqpAdmin;

    public RabbitMQFunctions(AmqpAdmin amqpAdmin) {
        this.amqpAdmin = amqpAdmin;
    }

    public void crearCola(String nombre) {
        Queue queue = new Queue(nombre, true); //persistente
        amqpAdmin.declareQueue(queue);         // Crea la cola en RabbitMQ
    }

    public boolean eliminarCola(String nombre) {
        boolean eliminado = amqpAdmin.deleteQueue(nombre);         // Elimina la cola
        return eliminado;
    }
}
