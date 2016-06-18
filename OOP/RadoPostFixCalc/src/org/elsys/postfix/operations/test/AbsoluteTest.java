package org.elsys.postfix.operations.test;

import static org.junit.Assert.assertEquals;

import org.elsys.postfix.Calculator;
import org.elsys.postfix.operations.Absolute;
import org.elsys.postfix.operations.TripleMultiply;
import org.junit.Test;

public class AbsoluteTest {
	@Test
	public void test() {
		Calculator calculator = new Calculator();
		Absolute tm = new Absolute(calculator, "abs");
		calculator.addValue(-5);
		tm.calculate();
		assertEquals(5, calculator.popValue(), 0.00001);
	}
	
	@Test
	public void testPositive() {
		Calculator calculator = new Calculator();
		Absolute tm = new Absolute(calculator, "abs");
		calculator.addValue(5);
		tm.calculate();
		assertEquals(5, calculator.popValue(), 0.00001);
	}
	
	@Test(expected=IndexOutOfBoundsException.class)
	public void testLessValues() {
		Calculator calculator = new Calculator();
		Absolute tm = new Absolute(calculator, "abs");
		tm.calculate();
		assertEquals(5, calculator.popValue(), 0.00001);
	}
}
