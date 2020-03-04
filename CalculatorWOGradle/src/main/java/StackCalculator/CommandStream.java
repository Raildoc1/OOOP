package StackCalculator;

import StackCalculator.Command.CommandFactory;
import StackCalculator.Command.ICommand;
import StackCalculator.Exceptions.CommandNotFound;
import StackCalculator.Exceptions.WrongConfigFileFormat;

import java.io.*;
import java.lang.reflect.InvocationTargetException;

public class CommandStream {

    private BufferedReader reader;
    private CommandFactory factory;

    public CommandStream(String configFileName) throws NoSuchMethodException, IOException, InstantiationException, WrongConfigFileFormat, IllegalAccessException, InvocationTargetException, ClassNotFoundException {
        factory = new CommandFactory(configFileName);
        reader = new BufferedReader(new InputStreamReader(System.in));
    }

    public CommandStream(String fileName, String configFileName) throws IOException, NoSuchMethodException, WrongConfigFileFormat, InstantiationException, IllegalAccessException, InvocationTargetException, ClassNotFoundException {
        factory = new CommandFactory(configFileName);
        reader = new BufferedReader(new FileReader(fileName));
    }

    public ICommand NextCommand() throws IOException, CommandNotFound {
        String line;
        if((line = reader.readLine()) == null) return null;
        String[] tmp = CommandFileParser.split(line);
        if(tmp.length == 1)
            return factory.CreateCommand(tmp[0], null);
        else
            return factory.CreateCommand(tmp[0], tmp[1]);
    }

    public void Close() throws IOException {
        reader.close();
    }

}
