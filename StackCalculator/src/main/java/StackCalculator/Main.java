package StackCalculator;

import StackCalculator.Command.CommandFactory;
import StackCalculator.Command.Invert;
import StackCalculator.Command.Sum;
import StackCalculator.Exceptions.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.text.ParseException;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        try {
            calculator.ExecuteCommands("in.txt", "cfg.txt");
        } catch (WrongConfigFileFormat wrongConfigFileFormat) {
            wrongConfigFileFormat.PrintError();
        } catch (WrongAmountOfArguments wrongAmountOfArguments) {
            wrongAmountOfArguments.PrintArguments();
        } catch (VarNameHasAlreadyExist varNameHasAlreadyExist) {
            varNameHasAlreadyExist.PrintError();
        } catch (UndefinedVariable undefinedVariable) {
            undefinedVariable.PrintError();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
