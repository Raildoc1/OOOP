package ru.carFactory;

import ru.carFactory.Details.Accessory;
import ru.carFactory.Details.Body;
import ru.carFactory.Details.Engine;

public class Task extends Thread {

    long deltaTime;
    Factory factory;

    public Task(long deltaTime, Factory factory) {
        this.deltaTime = deltaTime;
        this.factory = factory;

    }

    @Override
    public void run() {
        try {
            Thread.sleep(deltaTime);
            Car car = new Car(factory.getEngineStorage().pop(), factory.getBodyStorage().pop(), factory.getAccessoryStorage().pop());
            factory.getCarStorage().add(car);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
