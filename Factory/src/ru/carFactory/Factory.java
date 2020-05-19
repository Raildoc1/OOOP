package ru.carFactory;

import ru.carFactory.Details.Accessory;
import ru.carFactory.Details.Body;
import ru.carFactory.Details.Engine;

import java.awt.*;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Properties;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class Factory {

    private static final String config = "resources/config.cfg";

    private ExecutorService storageControllerExecutorService;
    private ExecutorService workersExecutorService;
    private ExecutorService dealersExecutorService;
    private ExecutorService suppliersExecutorService;

    private Storage<Car> carStorage;
    private Storage<Engine> engineStorage;
    private Storage<Accessory> accessoryStorage;
    private Storage<Body> bodyStorage;

    private Supplier<Engine> engineSupplier;
    private Supplier<Body> bodySupplier;
    private ArrayList<Supplier<Accessory>> accessorySuppliers;
    private ArrayList<Dealer> dealers;

    private long engineSupplierDeltaTime;
    private long bodySupplierDeltaTime;
    private long accessorySupplierDeltaTime;
    private long dealerDeltaTime;
    private long workerDeltaTime;

    private int accessorySuppliersAmount;
    private int workersAmount;
    private int dealersAmount;
    //private boolean LogSale;

    public Factory() throws IOException {
        // Loading Properties
        Properties properties = new Properties();
        properties.load(Factory.class.getResourceAsStream(config));

        // Init vars
        carStorage = new Storage<Car>(Integer.parseInt(properties.getProperty("CarStorageSize")));
        engineStorage = new Storage<Engine>(Integer.parseInt(properties.getProperty("EngineStorageSize")));
        accessoryStorage = new Storage<Accessory>(Integer.parseInt(properties.getProperty("AccessoryStorageSize")));
        bodyStorage = new Storage<Body>(Integer.parseInt(properties.getProperty("BodyStorageSize")));
        accessorySuppliersAmount = Integer.parseInt(properties.getProperty("AccessorySuppliersAmount"));
        workersAmount = Integer.parseInt(properties.getProperty("WorkersAmount"));
        dealersAmount = Integer.parseInt(properties.getProperty("DealersAmount"));

        engineSupplierDeltaTime = Long.parseLong(properties.getProperty("EngineSupplierDeltaTime"));
        bodySupplierDeltaTime = Long.parseLong(properties.getProperty("BodySupplierDeltaTime"));
        accessorySupplierDeltaTime = Long.parseLong(properties.getProperty("AccessorySupplierDeltaTime"));
        dealerDeltaTime = Long.parseLong(properties.getProperty("DealerDeltaTime"));
        workerDeltaTime = Long.parseLong(properties.getProperty("WorkerDeltaTime"));

        // Init suppliers
        engineSupplier = new Supplier<Engine>(engineStorage, Engine.class, engineSupplierDeltaTime);
        bodySupplier = new Supplier<Body>(bodyStorage, Body.class, bodySupplierDeltaTime);
        accessorySuppliers = new ArrayList<Supplier<Accessory>>();
        for(int i = 0; i < accessorySuppliersAmount; i++) {
            accessorySuppliers.add(new Supplier<Accessory>(accessoryStorage, Accessory.class, accessorySupplierDeltaTime));
        }
        dealers = new ArrayList<Dealer>();
        for(int i = 0; i < dealersAmount; i++) {
            dealers.add(new Dealer(this, dealerDeltaTime));
        }
        storageControllerExecutorService = Executors.newSingleThreadExecutor();
        workersExecutorService = Executors.newFixedThreadPool(workersAmount);
    }

    public void run() {
        engineSupplier.start();
        bodySupplier.start();
        for(Supplier<Accessory> s : accessorySuppliers) {
            s.start();
        }
        for(Dealer d : dealers) {
            d.start();
        }
        StorageController controller = new StorageController(carStorage, workersExecutorService, this);
        carStorage.addToUpdate(controller);
        controller.OnStorageUpdate();
        //storageControllerExecutorService.submit(new StorageController(carStorage, workersExecutorService, this));

    }

    public Storage<Engine> getEngineStorage() {
        return engineStorage;
    }

    public Storage<Body> getBodyStorage() {
        return bodyStorage;
    }

    public Storage<Accessory> getAccessoryStorage() {
        return accessoryStorage;
    }

    public Storage<Car> getCarStorage() {
        return carStorage;
    }

    public Task getNewTask() {
        return new Task(workerDeltaTime, this);
    }

    public int getCarAmount() {
        int activeCars = ((ThreadPoolExecutor)workersExecutorService).getActiveCount();
        int waitingCars = ((ThreadPoolExecutor)workersExecutorService).getQueue().size();
        int inStorage = carStorage.getAmount();
        return activeCars + waitingCars + inStorage;
    }
}
