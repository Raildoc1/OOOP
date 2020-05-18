package ru.carFactory;

import java.util.concurrent.ExecutorService;

public class StorageController extends Thread implements Runnable {

    private Storage<Car> carStorage;
    private ExecutorService workersExecutorService;
    private Factory factory;

    public StorageController(Storage<Car> carStorage, ExecutorService workersExecutorService, Factory factory) {
        this.carStorage = carStorage;
        this.workersExecutorService = workersExecutorService;
        this.factory = factory;
    }

    @Override
    public void run() {
        while(!isInterrupted()) {
            for(int i = factory.getCarAmount(); i < carStorage.getSize(); i++) {
                workersExecutorService.submit(factory.getNewTask());
            }
        }
    }

}
