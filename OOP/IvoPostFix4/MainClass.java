package org.elsys.postfix;

import org.elsys.postfix.operations.*;

public class MainClass {

	public static void main(String[] args) {
		Calculator calculator = new Calculator();
		calculator.addOperation(new BinaryPlus(calculator, "+"));
		calculator.addOperation(new BinaryMinus(calculator, "-"));
		calculator.addOperation(new UnaryMinus(calculator, "neg"));	
		calculator.run();
	}
}
