package ooop.java.lab1;

import java.io.IOException;

public class Main {

	public static void main(String[] args) {
		
		TextStats textStats = new TextStats("input.txt");
		
		try {
			textStats.FileToSortedCSV("output.csv");
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

}
