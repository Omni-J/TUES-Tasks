package org.elsys.ip.socket;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client {
	private Socket socket;
	
	public Client(String hostname, int port) throws UnknownHostException, IOException {
		socket = new Socket(hostname, port);
	}
	
	public void start() throws IOException {
		Scanner scanner = new Scanner(System.in);
		PrintStream ps = new PrintStream(socket.getOutputStream());
		
		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			
			ps.println(line);
			
			ps.flush();
		}
	}
}
