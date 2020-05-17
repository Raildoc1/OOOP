package ru.carFactory;

import ru.carFactory.Details.Accessory;
import ru.carFactory.Details.Body;
import ru.carFactory.Details.Engine;

import java.io.IOException;
import java.util.Properties;
import java.util.concurrent.ExecutorService;

public class factory {
    private static final String config = "config.cfg";
    private ExecutorService executorService;

    private Storage<Car> CarStorage;
    private Storage<Engine> EngineStorage;
    private Storage<Accessory> AccessoryStorage;
    private Storage<Body> BodyStorage;

    private int AccessorySuppliersAmount;
    private int WorkersAmount;
    private int DealersAmount;
    //private boolean LogSale;

    public factory() throws IOException {
        // Loading Properties
        Properties properties = new Properties();
        properties.load(factory.class.getResourceAsStream(config));

        // Init vars
        CarStorage = new Storage<Car>(Integer.parseInt(properties.getProperty("StorageAutoSize")));
        EngineStorage = new Storage<Engine>(Integer.parseInt(properties.getProperty("StorageEngineSize")));
        AccessoryStorage = new Storage<Accessory>(Integer.parseInt(properties.getProperty("StorageAccessorySize")));
        BodyStorage = new Storage<Body>(Integer.parseInt(properties.getProperty("StorageBodySize")));
        AccessorySuppliersAmount = Integer.parseInt(properties.getProperty("AccessorySuppliers"));
        WorkersAmount = Integer.parseInt(properties.getProperty("Workers"));
        DealersAmount = Integer.parseInt(properties.getProperty("Dealers"));
    }
}
