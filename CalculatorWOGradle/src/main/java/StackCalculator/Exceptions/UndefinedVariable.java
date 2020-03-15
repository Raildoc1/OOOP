package StackCalculator.Exceptions;

public class UndefinedVariable extends Exception {
    public UndefinedVariable(String name) {
        super("Undefined var name: " + name);
    }
}
