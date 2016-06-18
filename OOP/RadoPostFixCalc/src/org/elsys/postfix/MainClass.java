package org.elsys.postfix;

import org.elsys.postfix.operations.Absolute;
import org.elsys.postfix.operations.Plus;
import org.elsys.postfix.operations.TripleMultiply;

public class MainClass {

	public static void main(String[] args) {
		Calculator calculator = new Calculator();
		calculator.addOperation(new Plus(calculator, "+"));
		calculator.addOperation(new Absolute(calculator, "abs"));
		calculator.addOperation(new TripleMultiply(calculator, "*-*"));
		calculator.run();
	}

}
