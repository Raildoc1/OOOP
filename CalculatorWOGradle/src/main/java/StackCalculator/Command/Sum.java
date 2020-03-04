package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Sum implements ICommand {

    @Override
    public void putArgs(String args) {}

    @Override
    public ICommand.retValue Execute(String[] args, CalcMemory memory) throws WrongAmountOfArguments {
        if(args.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[1]);
        if (DEV_MODE) System.out.println(b + " + " + a + " = " + (b + a));
        return new ICommand.retValue(a + b);
    }

    @Override
    public int GetArgumentsAmount() {
        return 2;
    }

}
