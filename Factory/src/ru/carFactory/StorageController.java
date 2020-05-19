package ru.carFactory;

import java.util.concurrent.ExecutorService;

public class StorageController implements IStorageController {

    private Storage<Car> carStorage;
    private ExecutorService workersExecutorService;
    private Factory factory;

    public StorageController(Storage<Car> carStorage, ExecutorService workersExecutorService, Factory factory) {
        this.carStorage = carStorage;
        this.workersExecutorService = workersExecutorService;
        this.factory = factory;
    }

    @Override
    public void OnStorageUpdate() {
        for(int i = factory.getCarAmount(); i < carStorage.getSize(); i++) {
            workersExecutorService.submit(factory.getNewTask());
        }
    }
}
