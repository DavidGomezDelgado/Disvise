package com.disvise.disvise.advise;

import java.time.LocalDate;

//Objeto que se almacenará en una lista o BBDD
public class Advise {
    //La lista de todas las peticiones se gestionarán por RabbitMQ

    //Necesitamos almacenar una lista de elementos:
    private int priority; //Entero que indique la prioridad, a igualdad de prioridad seguirá un FIFO

    private Long MagicNumber; //Magic Number encargado de filtrar si la petición ha sido realizada desde este programa (Seguridad)

    private AdviseToControler advise;

    private LocalDate date; //La hora local

    private String destiny; //Un id que almacenará a qué cola de RabbitMQ enviará la información

    //Constructor completo
    public Advise(int priority, Long magicNumber, AdviseToControler advise, LocalDate date, String destiny) {
        if (advise == null) {
            throw new IllegalArgumentException("El parámetro 'advise' no puede ser null");
        }else{
            this.priority = priority;
            MagicNumber = magicNumber;
            this.advise = new AdviseToControler(advise.getFunction());
            this.date = date;
            this.destiny = destiny;
        }

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

    public AdviseToControler getAdvise() {
        return advise;
    }

    public void setAdvise(AdviseToControler advise) {
        this.advise = advise;
    }


    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public String getDestiny() {
        return destiny;
    }

    public void setDestiny(String destiny) {
        this.destiny = destiny;
    }
}

