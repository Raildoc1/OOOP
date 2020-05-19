package ru.carFactory;

import ru.carFactory.Details.Detail;
import ru.carFactory.Details.Engine;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.WildcardType;

public class Supplier<T extends Detail> extends Thread {
    private Storage<T> storage;
    private long deltaTime;
    private Class<T> detailFactory;

    public Supplier(Storage<T> storage, Class<T> detailFactory, long deltaTime) {
        this.storage = storage;
        this.deltaTime = deltaTime;
        this.detailFactory = detailFactory;
    }

    @Override
    public void run() {
        while(!isInterrupted()) {
            try{
                storage.add(detailFactory.getDeclaredConstructor().newInstance());
                Thread.sleep(deltaTime);
            } catch (InterruptedException e) {
                break;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
