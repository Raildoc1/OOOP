package StackCalculator.Command;

import StackCalculator.Exceptions.UndefinedVariable;
import StackCalculator.Exceptions.VarNameHasAlreadyExist;
import StackCalculator.Exceptions.WrongAmountOfArguments;

public interface ICommand {

    retValue Execute(String[] args) throws WrongAmountOfArguments, VarNameHasAlreadyExist, UndefinedVariable;

    public void putArgs(String args);

    public int GetArgumentsAmount();

    public class retValue {

        public double value;
        public boolean hasValue;

        retValue() {
            hasValue = false;
        }

        retValue(double value) {
            this.value = value;
            hasValue = true;
        }
    }
}
