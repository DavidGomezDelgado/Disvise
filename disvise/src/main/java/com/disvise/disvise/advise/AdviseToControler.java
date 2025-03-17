package com.disvise.disvise.advise;

public class AdviseToControler {
    private int function; //Un entero encargado de decir qué funcion del microcontrolador se va a realizar

    private int place; //Otro entero que indica un lugar, esto va a usar para saber que icono mostrar en la pantalla

    public AdviseToControler(int function, int place) {
        this.function = function;
        this.place = place;
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
}
