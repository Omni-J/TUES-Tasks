package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class BinaryMinus extends BinaryOperation {

	public BinaryMinus(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public double binaryCalculate(double firstOperand, double secondOperand) {
		return firstOperand - secondOperand;
	}
}