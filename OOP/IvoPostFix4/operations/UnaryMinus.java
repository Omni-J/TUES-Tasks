package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class UnaryMinus extends UnaryOperation {

	public UnaryMinus(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public double unaryCalculate(double operand) {
		return -operand;
	}
}