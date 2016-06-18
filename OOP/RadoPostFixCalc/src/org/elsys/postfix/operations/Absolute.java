package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Absolute extends OperationImpl implements Operation {

	public Absolute(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		Double value1 = getCalculator().popValue();
		Double result = Math.abs(value1);
		this.handleResult(result);
	}

}
