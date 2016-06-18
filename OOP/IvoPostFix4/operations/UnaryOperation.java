package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class UnaryOperation extends AbstractOperation {

	public UnaryOperation(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		Double value1 = getCalculator().popValue();
		
		double result = this.unaryCalculate(value1);
		getCalculator().addValue(result);
		
		System.out.println(result);		
	}
	
	public abstract double unaryCalculate(double operand);
}
