package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Sqrt implements ICommand {
    @Override
    public retValue Execute(String[] args, CalcMemory memory) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(args.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        if (DEV_MODE) System.out.println("sqrt(" + Double.parseDouble(args[0]) + ") = " + Math.sqrt(Double.parseDouble(args[0])));
        return new retValue(Math.sqrt(Double.parseDouble(args[0])));
    }

    @Override
    public void putArgs(String args) {

    }

    @Override
    public int GetArgumentsAmount() {
        return 1;
    }
}
