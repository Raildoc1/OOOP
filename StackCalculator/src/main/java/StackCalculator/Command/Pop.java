package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Pop implements ICommand {

    private String args;

    @Override
    public retValue Execute(String[] args) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(args.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        String name = this.args;
        double value = Double.parseDouble(args[0]);
        CalcMemory.getInstance().put(name, value);
        return new ICommand.retValue();
    }

    @Override
    public void putArgs(String args) {
        this.args = args;
    }

    @Override
    public int GetArgumentsAmount() {
        return 1;
    }
}
