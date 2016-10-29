package org.elsys.ip;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class MainClass {
	
	public static void main(String[] args) throws UnknownHostException, IOException{
		Socket socket = new Socket("www.example.com", 80);
		
		OutputStream outputStream =  socket.getOutputStream();
		PrintStream out = new PrintStream(outputStream);
		
		out.println("GET /index.html HTTP/1.1");
		out.println("Host:www.example.com");
		out.println("Connection:close");
		out.println("");
		
		Scanner scanner = new Scanner(socket.getInputStream());
		
		while(scanner.hasNextLine()){
			System.out.println(scanner.nextLine());
		}
		scanner.close();
		out.close();
		socket.close();
	}

}
