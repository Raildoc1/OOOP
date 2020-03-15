package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Define implements ICommand {

    private String args;

    @Override
    public retValue Execute(String[] values, CalcMemory memory) throws WrongAmountOfArguments, NumberFormatException, VarNameHasAlreadyExist {
        if(values != null) throw new WrongAmountOfArguments(values, GetArgumentsAmount());
        String[] NameAndValue = this.args.split(" ", 2);
        String name = NameAndValue[0];
        double value = Double.parseDouble(NameAndValue[1]);
        memory.put(name, value);
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
