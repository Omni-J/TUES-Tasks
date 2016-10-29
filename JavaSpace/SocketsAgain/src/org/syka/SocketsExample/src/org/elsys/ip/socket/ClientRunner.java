package org.elsys.ip.socket;

import java.io.IOException;

public class ClientRunner {
	
	public static void main(String[] args) throws IOException {
		Client client = new Client("localhost", 10000);
		client.start();
	}

}
