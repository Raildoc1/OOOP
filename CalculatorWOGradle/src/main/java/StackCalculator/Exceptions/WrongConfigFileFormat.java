package StackCalculator.Exceptions;

public class WrongConfigFileFormat extends Exception {
    public WrongConfigFileFormat(String got, String necessary) {
        super("Wrong config file format: " + got + necessary + " was expected!");
    }
}
