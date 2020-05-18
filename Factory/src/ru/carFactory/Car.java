package ru.carFactory;

import ru.carFactory.Details.Accessory;
import ru.carFactory.Details.Body;
import ru.carFactory.Details.Engine;

import java.util.function.DoubleToLongFunction;

public class Car {

    private final int ID;
    private static int amount = 0;
    Engine engine;
    Body body;
    Accessory accessory;

    public Car(Engine engine, Body body, Accessory accessory) {
        ID = amount++;
        this.engine = engine;
        this.body = body;
        this.accessory = accessory;
    }

    public int getID() {
        return ID;
    }
    public int getEngineID() { return engine.getID(); }
    public int getBodyID() { return body.getID(); }
    public int getAccessoryID() { return accessory.getID(); }
}
