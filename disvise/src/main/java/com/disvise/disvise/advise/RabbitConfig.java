package com.disvise.disvise.advise;

import org.springframework.amqp.core.Queue;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class RabbitConfig {

    // Define la cola 'requests' para que se cree automáticamente al iniciar la aplicación
    @Bean
    public Queue requestsQueue() {
        return new Queue("requests", true);  // 'true' asegura que la cola sea persistente
    }
}