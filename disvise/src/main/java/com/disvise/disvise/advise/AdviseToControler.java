package com.disvise.disvise.advise;

public class AdviseToControler {
    private int function; //Un entero encargado de decir qué funcion del microcontrolador se va a realizar

    public AdviseToControler (int function) {
        this.function = function;
    }

    public int getFunction() {
        return function;

    }

    public void setFunction(int function) {
        this.function = function;

    }

}
