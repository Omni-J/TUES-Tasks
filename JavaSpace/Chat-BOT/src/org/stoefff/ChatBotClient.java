package org.stoefff;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class ChatBotClient {
	
	private static final String HOST = "localhost";
	private static final int PORT = 31333;
	
	public static void main(String[] args) throws UnknownHostException, IOException {
	
		try(Socket clientSocket = new Socket(HOST, PORT);
			PrintStream output = new PrintStream(clientSocket.getOutputStream());
			Scanner input = new Scanner(clientSocket.getInputStream());
			Scanner stdIn = new Scanner(System.in);){
			
			String userInput;
			
			while((userInput = stdIn.nextLine()) != null){
				output.println(userInput);
				System.out.println(input.nextLine());
			}
		}
		
	}

}
