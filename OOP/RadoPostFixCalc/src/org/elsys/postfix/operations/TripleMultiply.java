package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class TripleMultiply extends OperationImpl implements Operation{
	public TripleMultiply(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		Double[] values = this.getValues(3);
		double result = -(values[0] * values[1] * values[2]);
		this.handleResult(result);
	}

}
