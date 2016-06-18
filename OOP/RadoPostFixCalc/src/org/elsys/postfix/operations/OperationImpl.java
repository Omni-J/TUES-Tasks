package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public abstract class OperationImpl extends AbstractOperation {

	public OperationImpl(Calculator calculator, String token) {
		super(calculator, token);
	}

	public Double[] getValues(int count) {
		Double[] values = new Double[count];
		for(int i = 0; i < count; i++) {
			try {
				values[i] = getCalculator().popValue();
			} catch(IndexOutOfBoundsException e) {
				throw new IndexOutOfBoundsException();
			}
		}
		
		return values;
	}
	
	public void handleResult(Double result) {
		getCalculator().addValue(result);
		System.out.println(result);
	}
}
