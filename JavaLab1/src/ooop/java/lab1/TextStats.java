package ooop.java.lab1;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;

public class TextStats {
	
	private int WordsAmount = 0;
	
	private HashMap<String, Integer> words;
	
	private String inputFileName;
	
	public TextStats(String inputFileName) {
		this.inputFileName = inputFileName;
		words = new HashMap<String, Integer>();
	}
	
	public void AddWord(String word) {
		
		if(words.containsKey(word)) {
			words.merge(word, 1, Integer::sum);
		} else {
			words.put(word, 1);
		}
		
		WordsAmount++;
	}
	
	public void FileToMap() throws IOException {
		Parser parser = new Parser(inputFileName);
		String word = "";
		while((word = parser.NextWord()) != null) {
			if(!word.contentEquals(""))  {
				AddWord(word);
			}
		}
	}
	
	public void PrintWords() {
		for(HashMap.Entry<String, Integer> entry : words.entrySet()) {
			System.out.print(entry.getKey());
			System.out.print(" ");
			System.out.println(entry.getValue());
		}
	}
	
	public void PrintWordsCSV() {
		for(HashMap.Entry<String, Integer> entry : words.entrySet()) {
			System.out.print(entry.getKey());
			System.out.print(",");
			System.out.print(entry.getValue());
			System.out.print(",");
			System.out.println(entry.getValue() * 100 / (float)WordsAmount);
			
			
		}
	}
	
	public void PrintWordsCSV(String fileName) throws IOException {
		
		FileWriter writer = new FileWriter(fileName);
		
		for(HashMap.Entry<String, Integer> entry : words.entrySet()) {
			writer.write(entry.getKey());
			writer.write(',');
			writer.write(entry.getValue().toString());
			writer.write(',');
			float percent = entry.getValue() * 100 / (float)WordsAmount;
			writer.write(String.valueOf(percent) + '\n');
		}
		
		writer.close();
	}
	
	public void FileToSortedCSV(String fileName) throws IOException {
		FileToMap();
		words = ReverseSortWords();
		PrintWordsCSV(fileName);
	}
	
	public int GetWordsAmount() {
		return WordsAmount;
	}
	
	private HashMap<String, Integer> ReverseSortWords() {
		
        LinkedHashMap<String, Integer> sortedWords = new LinkedHashMap<>();

        words.entrySet().stream().sorted(HashMap.Entry.comparingByValue(Comparator.reverseOrder())).forEachOrdered(x -> sortedWords.put(x.getKey(), x.getValue()));

        return sortedWords;
    }
}
