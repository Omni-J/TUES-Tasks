package org.elsys.ip.socket;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
	private ServerSocket serverSocket;
	
	public Server(int port) throws IOException {
		serverSocket = new ServerSocket(port);
	}
	
	public void start() throws IOException {
		Socket client = serverSocket.accept();
		
		Scanner scanner = new Scanner(client.getInputStream());
		
		while (scanner.hasNext()) {
			String nextLine = scanner.nextLine();
			System.out.println(nextLine);
		}
	}

}
