package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Sum implements ICommand {

    @Override
    public void putArgs(String args) {}

    @Override
    public ICommand.retValue Execute(String[] values, CalcMemory memory) throws WrongAmountOfArguments {
        if(values.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(values, GetArgumentsAmount());
        double a = Double.parseDouble(values[0]);
        double b = Double.parseDouble(values[1]);
        if (DEV_MODE) System.out.println(b + " + " + a + " = " + (b + a));
        return new ICommand.retValue(a + b);
    }

    @Override
    public int GetArgumentsAmount() {
        return 2;
    }

}
