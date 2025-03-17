package com.disvise.disvise.advise;

import java.time.LocalDate;

public class Advise {
    //La lista de todas las peticiones se gestionarán por RabbitMQ

    //Necesitamos almacenar una lista de elementos:
    private int priority; //Entero que indique la prioridad, a igualdad de prioridad seguirá un FIFO

    private Long MagicNumber; //Magic Number encargado de filtrar si la petición ha sido realizada desde este programa (Seguridad)

    private int function; //Un entero encargado de decir qué funcion del microcontrolador se va a realizar

    private int place; //Otro entero que indica un lugar, esto va a usar para saber que icono mostrar en la pantalla

    private LocalDate date; //La hora local

    private int destiny; //Un id que almacenará a qué cola de RabbitMQ enviará la información (elemento no guardable en la lista pero muy útil)

    //Constructor completo
    public Advise(int priority, Long magicNumber, int function, int place, LocalDate date, int destiny) {
        this.priority = priority;
        MagicNumber = magicNumber;
        this.function = function;
        this.place = place;
        this.date = date;
        this.destiny = destiny;
    }
    //Constructor vacio
    public Advise(){

    }

    public int getPriority() {
        return priority;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }

    public Long getMagicNumber() {
        return MagicNumber;
    }

    public void setMagicNumber(Long magicNumber) {
        MagicNumber = magicNumber;
    }

    public int getFunction() {
        return function;
    }

    public void setFunction(int function) {
        this.function = function;
    }

    public int getPlace() {
        return place;
    }

    public void setPlace(int place) {
        this.place = place;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public int getDestiny() {
        return destiny;
    }

    public void setDestiny(int destiny) {
        this.destiny = destiny;
    }
}

