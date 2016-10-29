package org.paynersoft;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.ReentrantLock;
//import java.util.concurrent.atomic.AtomicLong;

/* Problem solved with the book tips */

public class MainClass {
	
	/* Why not and how AtomicLong ?? */
	private int elves = 0; //Counter protected by the mutex, checked by santa
	private int raindeer = 0; // Counter protected by the mutex, checked by santa 
	private Semaphore santaSem = new Semaphore(0); // santa waits it this until signal from e|d
	private Semaphore raindeerSem = new Semaphore(0); // waits for santa to get hitched
	private Semaphore elfTex = new Semaphore(1);// prevents more than 3 elves interfering 
	private ReentrantLock mutex = new ReentrantLock();// lock for counters
	
	
	public void prepareSleigh() {
		
	}
	public static void main(){
	
	}
	
	public void helpElves(){
		
	}
	
}
