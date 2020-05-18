package ru.carFactory;

import ru.carFactory.Details.Detail;

import java.lang.reflect.InvocationTargetException;

public class Supplier<T extends Detail> extends Thread {
    private Storage<T> storage;
    private double deltaTime;
    private Class<T> detailFactory;

    public Supplier(Storage<T> storage, Class<T> detailFactory, double deltaTime) {
        this.storage = storage;
        this.deltaTime = deltaTime;
        this.detailFactory = detailFactory;
    }

    @Override
    public void run() {
        while(!isInterrupted()) {
            try{
                storage.add(detailFactory.getDeclaredConstructor().newInstance());
            } catch (InterruptedException e) {
                break;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
