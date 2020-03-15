package StackCalculator.Exceptions;

public class VarNameHasAlreadyExist extends Exception {
    public VarNameHasAlreadyExist(String name) {
        super("Var name: " + name + " has already exist!");
    }
}
