package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class BinaryOperation extends AbstractOperation implements Operation {

	public BinaryOperation(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		Double value1 = getCalculator().popValue();
		Double value2 = getCalculator().popValue();
		
		double result = this.binaryCalculate(value2, value1);
		getCalculator().addValue(result);
		
		System.out.println(result);
	}

	public abstract double binaryCalculate(double firstOperand, double secondOperand); 
}
