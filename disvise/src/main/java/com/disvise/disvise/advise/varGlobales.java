package com.disvise.disvise.advise;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class varGlobales {
    // Variables globales (modificables)
    public static long magicNumber = 123456;

    public static final List<String> listaGlobal =
            Collections.synchronizedList(new ArrayList<>()); //Escalable por si se necesitan hilos

    public static int prioridades = 2;

    public static String BBDD_URL = ".jdbc:sqlite:C:/Users/12401/Documents/TFG_David/Disvise/disvise/src/main/java/com/disvise/disvise/advise.db";
}
