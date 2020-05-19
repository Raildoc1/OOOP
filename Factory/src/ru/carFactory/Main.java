package ru.carFactory;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        Factory factory = new Factory();
        factory.run();
        System.in.read();
        factory.stop();
    }
}
