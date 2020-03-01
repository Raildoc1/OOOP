package StackCalculator.Exceptions;

public class UndefinedVariable extends Exception {
    String name;

    public void PrintError() {
        System.out.println("Undefined var name: " + name);
    }

    public UndefinedVariable(String name) {
        this.name = name;
    }
}
