package StackCalculator.Exceptions;

public class WrongConfigFileFormat extends Exception {

    String got;
    String necessary;

    public void PrintError() {
        System.out.println("Wrong config file format: " + got);
        System.out.println(necessary + " was expected!");
    }

    public WrongConfigFileFormat(String got, String necessary) {
        this.got = got;
        this.necessary = necessary;
    }
}
