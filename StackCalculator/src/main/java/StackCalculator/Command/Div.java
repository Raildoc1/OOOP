package StackCalculator.Command;

import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Div implements ICommand {
    @Override
    public retValue Execute(String[] args) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable, ArithmeticException {
        if(args.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[1]);
        if (a == 0) throw new ArithmeticException();
        return new ICommand.retValue(b / a);
    }

    @Override
    public void putArgs(String args) { }

    @Override
    public int GetArgumentsAmount() {
        return 2;
    }
}
