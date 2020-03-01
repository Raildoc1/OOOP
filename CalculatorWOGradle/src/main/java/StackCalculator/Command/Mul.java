package StackCalculator.Command;

import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Mul implements ICommand {
    @Override
    public retValue Execute(String[] args) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(args.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[1]);
        return new ICommand.retValue(a * b);
    }

    @Override
    public void putArgs(String args) { }

    @Override
    public int GetArgumentsAmount() {
        return 2;
    }
}
