package StackCalculator.Command;

import StackCalculator.ConfigParser;
import StackCalculator.Exceptions.CommandNotFound;
import StackCalculator.Exceptions.WrongConfigFileFormat;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.Map;

public class CommandFactory implements ICommandFactory {

    private Map<String, ICommand> commandsList;

    public CommandFactory(String configFileName) throws IOException, WrongConfigFileFormat, ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {

        commandsList = new HashMap<String, ICommand>();

        Map<String, String> tmp = ConfigParser.ConvertConfigFileToMap(configFileName);

        for(Map.Entry<String, String> entry : tmp.entrySet()) {
            System.out.println("\'" + entry.getValue() + "\'");
            ICommand command = (ICommand)(Class.forName(entry.getValue()).getDeclaredConstructor().newInstance());
            commandsList.put(entry.getKey(), command);
        }
    }

    @Override
    public ICommand CreateCommand(String name, String parameters) throws CommandNotFound {
        ICommand command = commandsList.get(name);
        if(command == null) throw new CommandNotFound();
        command.putArgs(parameters);
        return command;
    }
}
