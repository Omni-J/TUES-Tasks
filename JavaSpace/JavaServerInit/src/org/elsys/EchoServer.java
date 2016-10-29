package org.elsys;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

import org.omg.CORBA.portable.InputStream;

public class EchoServer extends Thread {
	
	private ServerSocket socket;
	private boolean running = true;
	public EchoServer(int port){
		try {
			socket = new ServerSocket(port);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.err.println("Port already in use");
			System.exit(-1);
		}
		System.out.println("Server Started on port: " + port);
	}
	
	@Override
	public void run() {
		while(running){
			try(
					Socket client = socket.accept();
					Scanner inScanner = new Scanner(client.getInputStream());
					PrintWriter outWriter =
							new PrintWriter(client.getOutputStream());
			) {
				System.out.println("New client accepted");
				String input;
				while((input = inScanner.nextLine()) != null){
					System.out.println("Received: " + input);
					outWriter.println("Echo: " + input);
						
				}
			} catch(IOException e) {
				System.err.println("Print not able to handle request");
				System.exit(-1);
			} 
		}
	};
	
	public void shutDown() {
		System.out.println("Server shutting down");
		running = false;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new EchoServer(4444).start();

	}

}
