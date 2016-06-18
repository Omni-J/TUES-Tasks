package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Plus extends OperationImpl implements Operation {

	public Plus(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		Double[] values = this.getValues(2);
		double result = values[0] + values[1];
		this.handleResult(result);
	}

}
