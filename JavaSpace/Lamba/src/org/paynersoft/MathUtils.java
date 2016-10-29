package org.paynersoft;

import java.awt.List;
import java.math.BigDecimal;
import java.util.ArrayList;

public class MathUtils {
	
	public static double integrade(Integrable function, double begin,
			double end, int deltas){
		
		double interval = (end - begin) / deltas;
		double sum = 0;
		for(; begin < end; begin += interval){
			sum += interval * function.call(begin);
		}
		return sum; 
	}

	public static void main(String[] args) {
		List<Double> result = new ArrayList<>();
		result.add(MathUtils.integrade(x -> x * x, -2, 15.5, 1000));
		System.out.println("Integration of x^2: " + result);
		
		result.add(MathUtils.integrade(x -> Math.sin(x), 0, Math.PI*2, 1000));
		result.add(MathUtils.integrade(Math::sin, 0, Math.PI*2, 1000));
		result.forEach(System.out::println);
		result.stream()
			.map(Double::intValue)
			.forEach(System.out::println);
		
		result.stream()
			.map(BigDecimal::new)
			.forEach(System.out::println);
	}

}
