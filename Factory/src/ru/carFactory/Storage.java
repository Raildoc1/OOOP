package ru.carFactory;

import java.util.ArrayList;
import java.util.LinkedList;

public class Storage<T> {

    private int size;
    private LinkedList<T> items;

    public Storage(int size) {
        items = new LinkedList<T>();
        this.size = size;
    }

    public void add(T item) throws InterruptedException {
        synchronized (this) {
            if(items.size() >= size) {
                this.wait();
            }
            items.add(item);
            notify();
        }
    }

    public T pop() throws InterruptedException {
        synchronized (this){
            while (items.size() == 0){
                this.wait();
            }
            T detail = items.pop();
            notify();
            return detail;
        }
    }

    public int getSize() {
        return size;
    }

    public int getAmount() {
        return items.size();
    }
}
