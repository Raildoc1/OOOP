package StackCalculator;

import StackCalculator.Exceptions.*;
import org.junit.*;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;

import static org.junit.Assert.*;

public class CalculatorTest {

    double actual, expected;
    double epsilon = 0.001;

    @Test
    public void ExecuteCommands() throws IOException, InstantiationException, InvocationTargetException, NoSuchMethodException, UndefinedVariable, IllegalAccessException, VarNameHasAlreadyExist, WrongAmountOfArguments, ClassNotFoundException, CommandNotFound, WrongConfigFileFormat {

        {
            Calculator calculator = new Calculator();

            calculator.ExecuteCommands("in.txt", "cfg.txt");
            actual = calculator.getStackTop();
            expected = 2.0;

            assertTrue(Math.abs(actual - expected) < epsilon);

        }

        {
            Calculator calculator = new Calculator();

            try {
                calculator.ExecuteCommands("in1.txt", "cfg.txt");
            } catch (VarNameHasAlreadyExist e) {
                e.PrintError();
            }
            actual = calculator.getStackTop();
            expected = 28.4632;

            assertTrue(Math.abs(actual - expected) < epsilon);

        }

        {
            Calculator calculator = new Calculator();

            try {
                calculator.ExecuteCommands("in2.txt", "cfg.txt");
            } catch (VarNameHasAlreadyExist e) {
                e.PrintError();
            }
            actual = calculator.getStackTop();
            expected = 13.8888;

            assertTrue(Math.abs(actual - expected) < epsilon);

        }
    }

}