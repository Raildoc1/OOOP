package ooop.java.lab1;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;

public class Parser {
	
	private Reader reader;
	
	private boolean isFinished = false;
	
	public Parser(String fileName) throws FileNotFoundException {
		reader = new InputStreamReader(new FileInputStream(fileName));
	}
	
	public String NextWord() throws IOException  {
		
		if(isFinished) return null;
		
		StringBuilder builder = new StringBuilder("");
		
		int c = reader.read(); 
		
		if(c == -1)  {
			reader.close();
			isFinished = true;
			return null;
		}
		
		while(Character.isLetterOrDigit(c)) {
			
			builder.append((char)c);
			
			if((c = reader.read()) == -1) {
				reader.close();
				isFinished = true;
				break;
			}
		}
		
		String word = builder.toString();
		
		return word;
	}
	
	public boolean IsFinished() {
		return isFinished;
	}
}
