package ru.carFactory;

import ru.carFactory.Details.Detail;

public class DetailsProvider<T extends Detail> {
    private Storage<T> storage;
    private double deltaTime;

}
