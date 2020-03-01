package StackCalculator.Exceptions;

public class VarNameHasAlreadyExist extends Exception {

    String name;

    public void PrintError() {
        System.out.println("Var name: " + name + " has already exist!");
    }

    public VarNameHasAlreadyExist(String name) {
        this.name = name;
    }
}
