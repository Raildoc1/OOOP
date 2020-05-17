package ru.carFactory.Details;

public class Accessory implements Detail {
    private final int ID;
    private static int amount = 0;

    public Accessory() {
        ID = amount++;
    }

    @Override
    public int getID() {
        return ID;
    }
}
