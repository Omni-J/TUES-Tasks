package org.elsys.postfix.operations.test;

import static org.junit.Assert.*;

import org.elsys.postfix.Calculator;
import org.elsys.postfix.operations.BinaryMinus;
import org.elsys.postfix.operations.BinaryPlus;
import org.elsys.postfix.operations.Operation;
import org.elsys.postfix.operations.UnaryMinus;
import org.junit.Test;

public class PlusTest {

	@Test
	public final void testBinaryPlus() {
		// Arrange
		Calculator calculator = new Calculator();
		Operation plus = new BinaryPlus(calculator, "+");
		
		// Act
		calculator.addOperation(plus);
		calculator.addValue(5);
		calculator.addValue(10);
		plus.calculate();
		
		// Assert
		assertEquals(15, calculator.popValue(), 0.00001);
	}

	@Test
	public final void testBinaryMinus() {
		// Arrange
		Calculator calculator = new Calculator();
		Operation minus = new BinaryMinus(calculator, "-");
		
		// Act
		calculator.addOperation(minus);
		calculator.addValue(10);
		calculator.addValue(5);
		minus.calculate();
		
		// Assert
		assertEquals(5, calculator.popValue(), 0.00001);
	}
	
	@Test
	public final void testUnaryMinus() {
		// Arrange
		Calculator calculator = new Calculator();
		Operation minus = new UnaryMinus(calculator, "neg");
		
		// Act
		calculator.addOperation(minus);
		calculator.addValue(10);
		minus.calculate();
		
		// Assert
		assertEquals(-10, calculator.popValue(), 0.00001);
	}	
}
