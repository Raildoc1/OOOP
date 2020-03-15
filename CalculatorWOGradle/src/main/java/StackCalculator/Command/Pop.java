package StackCalculator.Command;

import StackCalculator.CalcMemory;
import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public class Pop implements ICommand {

    private String args;

    @Override
    public retValue Execute(String[] values, CalcMemory memory) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable {
        if(values.length != GetArgumentsAmount()) throw new WrongAmountOfArguments(values, GetArgumentsAmount());
        String name = this.args;
        double value = Double.parseDouble(values[0]);
        memory.put(name, value);
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
