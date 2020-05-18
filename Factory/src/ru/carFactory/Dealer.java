package ru.carFactory;

public class Dealer extends Thread {

    private final int ID;
    private static int amount = 0;

    Factory factory;
    long deltaTime;

    public Dealer(Factory factory, long deltaTime) {
        this.deltaTime = deltaTime;
        this.factory = factory;
        ID = amount++;
    }

    @Override
    public void run() {
        while (!isInterrupted()) {
            try {
                Car car = factory.getCarStorage().pop();
                System.out.println("Dealer " + ID + ": Car=" + car.getID() + "(Engine=" + car.getEngineID() + ", Body=" + car.getBodyID()+ ")");
                Thread.sleep(deltaTime);
            } catch (InterruptedException e) {
                break;
            }
        }
    }
}
