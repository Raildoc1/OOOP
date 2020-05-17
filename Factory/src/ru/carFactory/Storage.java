package ru.carFactory;

import java.util.ArrayList;

public class Storage<T> {

    private int size;
    private ArrayList<T> items;

    public Storage(int size) {
        items = new ArrayList<T>();
        this.size = size;
    }

}
