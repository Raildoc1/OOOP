package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Invert implements ICommand {

    @Override
    public void putArgs(String args) {}

    @Override
    public ICommand.retValue Execute(String[] values, CalcMemory memory) throws WrongAmountOfArguments {
        if(values.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(values, GetArgumentsAmount());
        double a = -Double.parseDouble(values[0]);
        if (DEV_MODE) System.out.println("-" + -a + " = " + a);
        return new ICommand.retValue(a);
    }

    @Override
    public int GetArgumentsAmount() {
        return 1;
    }
}
