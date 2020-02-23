package StackCalculator.Exceptions;

import java.sql.SQLOutput;

public class WrongAmountOfArguments extends Exception {

    private String[] args;
    private int necessaryArgsAmount;

    public void PrintArguments() {
        System.out.println("Need " + necessaryArgsAmount + " arguments.");
        System.out.println("Got " + args.length + " arguments:");
        for(String s : args) {
            System.out.println(s);
        }
    }

    public WrongAmountOfArguments(String[] args, int necessaryArgsAmount) {
        this.args = args;
        this.necessaryArgsAmount = necessaryArgsAmount;
    }
}
