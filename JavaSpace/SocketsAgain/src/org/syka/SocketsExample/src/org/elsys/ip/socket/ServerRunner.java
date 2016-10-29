package org.elsys.ip.socket;

import java.io.IOException;

public class ServerRunner {

	private static final int SERVER_PORT = 10000; 

	public static void main(String[] args) throws IOException {
		Server server = new Server(SERVER_PORT);
		server.start();
	}

}
