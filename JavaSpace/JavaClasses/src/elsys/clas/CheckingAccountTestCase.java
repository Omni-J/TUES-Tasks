package elsys.clas;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class CheckingAccountTestCase {

	private CheckingAccount account;
	
	@Before
	public void setUp() throws Exception {
		account = new CheckingAccount(1000);
	}

	@After
	public void tearDown() throws Exception {
		account = null;
	}

	@Test
	public void test() {
		assertEquals(1000, account.getBalance());
	}
	
	@Test
	public void testDeposit() {
		account.deposit(1000);
		assertEquals(2000, account.getBalance());
	}

}
