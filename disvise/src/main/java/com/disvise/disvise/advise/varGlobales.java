package com.disvise.disvise.advise;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class varGlobales {
    // Variables globales (modificables)
    public static final List<String> listaGlobal =
            Collections.synchronizedList(new ArrayList<>()); //Escalable por si se necesitan hilos

    // Otros ejemplos
    public static int prioridades = 2;
}
