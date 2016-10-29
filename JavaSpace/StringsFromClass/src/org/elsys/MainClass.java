package org.elsys;

public class MainClass {

	public static void main(String[] args) throws InterruptedException {
		Thread thread = new ThreadImp(); // the thraead hasn't started
		thread.start();
		
		Thread.sleep(100);
		System.out.println("Exit from main...");
	}
}
