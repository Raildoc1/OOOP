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

            calculator.ExecuteCommands("src/main/resources/in.txt");
            actual = calculator.getStackTop();
            expected = 2.0;

            assertTrue(Math.abs(actual - expected) < epsilon);

        }

        {
            Calculator calculator = new Calculator();

            try {
                calculator.ExecuteCommands("src/main/resources/in1.txt");
            } catch (VarNameHasAlreadyExist e) {
                e.printStackTrace();
            }
            actual = calculator.getStackTop();
            expected = 28.4632;

            assertTrue(Math.abs(actual - expected) < epsilon);

        }

        {
            Calculator calculator = new Calculator();

            try {
                calculator.ExecuteCommands("src/main/resources/in2.txt");
            } catch (VarNameHasAlreadyExist e) {
                e.printStackTrace();
            }
            actual = calculator.getStackTop();
            expected = 13.8888;

            assertTrue(Math.abs(actual - expected) < epsilon);

        }
    }

}