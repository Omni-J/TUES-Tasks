package org.elsys.postfix.operations.test;

import static org.junit.Assert.*;

import org.elsys.postfix.Calculator;
import org.elsys.postfix.operations.Absolute;
import org.elsys.postfix.operations.Plus;
import org.elsys.postfix.operations.TripleMultiply;
import org.junit.Before;
import org.junit.Test;

public class TripleMultiplyTest {
	
	@Test
	public void test() {
		Calculator calculator = new Calculator();
		TripleMultiply tm = new TripleMultiply(calculator, "*-*");
		calculator.addValue(5);
		calculator.addValue(10);
		calculator.addValue(-1);
		tm.calculate();
		assertEquals(50, calculator.popValue(), 0.00001);
	}
	
	@Test(expected=IndexOutOfBoundsException.class)
	public void testLessValues() {
		Calculator calculator = new Calculator();
		TripleMultiply tm = new TripleMultiply(calculator, "abs");
		calculator.addValue(5);
		calculator.addValue(10);
		tm.calculate();
		assertEquals(5, calculator.popValue(), 0.00001);
	}
	
	@Test
	public void testNegativeValue() {
		Calculator calculator = new Calculator();
		TripleMultiply tm = new TripleMultiply(calculator, "*-*");
		calculator.addValue(5);
		calculator.addValue(10);
		calculator.addValue(1);
		tm.calculate();
		assertEquals(-50, calculator.popValue(), 0.00001);
	}
}
