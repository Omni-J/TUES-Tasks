package org.paynersoft;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class StreamExample {

	public static void main(String[] args) throws IOException{
		Files.lines(Paths.get("words.txt"))
			.filter(x -> x.length() > 3)
			.map(String::toUpperCase)
			.distinct()
			.forEach(System.out::println);
		Files.lines(Paths.get("words.txt"))
			.filter(x -> x.length() > 5)
			.mapToInt(String::hashCode)
			.average();
		if (average.isPresent()){
			System.out.println("Average hashCode: " + average.getAsDouble);
		}
		
	}
}
