package ru.carFactory.Details;

public class Body implements Detail {
    private final int ID;
    private static int amount = 0;

    public Body() {
        ID = amount++;
    }

    @Override
    public int getID() {
        return ID;
    }
}
