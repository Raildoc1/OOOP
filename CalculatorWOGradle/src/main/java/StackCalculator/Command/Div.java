package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Div implements ICommand {
    @Override
    public retValue Execute(String[] values, CalcMemory memory) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable, ArithmeticException {
        if(values.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(values, GetArgumentsAmount());
        double a = Double.parseDouble(values[0]);
        double b = Double.parseDouble(values[1]);
        if (b == 0) throw new ArithmeticException();
        if (DEV_MODE) System.out.println(a + " / " + b + " = " + (a / b));
        return new ICommand.retValue(a / b);
    }

    @Override
    public void putArgs(String args) { }

    @Override
    public int GetArgumentsAmount() {
        return 2;
    }
}
