package StackCalculator;

import StackCalculator.Exceptions.WrongConfigFileFormat;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class ConfigParser {
    public static Map<String, String> ConvertConfigFileToMap(String configFileName) throws IOException, WrongConfigFileFormat {
        BufferedReader reader = new BufferedReader(new FileReader(configFileName));

        Map<String, String> map = new HashMap<String, String>();

        String line;

        while((line = reader.readLine()) != null) {
            String[] lineParts = line.split(" ");
            if(lineParts.length != 2) throw new WrongConfigFileFormat(line, "<Name> <Operation> (Example: \"Sum +\")");
            map.put(lineParts[0], lineParts[1]);
        }

        reader.close();

        return map;
    }
}
