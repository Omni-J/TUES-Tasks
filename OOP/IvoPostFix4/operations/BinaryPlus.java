package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class BinaryPlus extends BinaryOperation {

	public BinaryPlus(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public double binaryCalculate(double firstOperand, double secondOperand) {
		return firstOperand + secondOperand;
	}
}
