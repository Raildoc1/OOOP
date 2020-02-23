package StackCalculator.Command;

import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;
import StackCalculator.CalcMemory;

public class Define implements ICommand {

    String args;

    @Override
    public retValue Execute(String[] args) throws WrongAmountOfArguments, NumberFormatException, VarNameHasAlreadyExist {
        if(args != null) throw new WrongAmountOfArguments(args, GetArgumentsAmount());
        String[] NameAndValue = this.args.split(" ", 2);
        String name = NameAndValue[0];
        double value = Double.parseDouble(NameAndValue[1]);
        CalcMemory.getInstance().put(name, value);
        return new ICommand.retValue();
    }

    @Override
    public void putArgs(String args) {
        this.args = args;
    }

    @Override
    public int GetArgumentsAmount() {
        return 0;
    }
}
