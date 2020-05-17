package ru.carFactory.Details;

public class Engine implements Detail {
    private final int ID;
    private static int amount = 0;

    public Engine() {
        ID = amount++;
    }

    @Override
    public int getID() {
        return ID;
    }
}
