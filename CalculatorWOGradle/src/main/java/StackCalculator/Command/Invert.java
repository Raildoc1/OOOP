package StackCalculator.Command;

import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Invert implements ICommand {

    @Override
    public void putArgs(String args) {}

    @Override
    public ICommand.retValue Execute(String[] args) throws WrongAmountOfArguments {
        if(args.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        double a = -Double.parseDouble(args[0]);
        if (DEV_MODE) System.out.println("-" + -a + " = " + a);
        return new ICommand.retValue(a);
    }

    @Override
    public int GetArgumentsAmount() {
        return 1;
    }
}
