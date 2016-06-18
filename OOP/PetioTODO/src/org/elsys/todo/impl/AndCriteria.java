package org.elsys.todo.impl;

import org.elsys.todo.Criteria;
import org.elsys.todo.Task;

public class AndCriteria extends AbstractCriteria implements Criteria {
	
	private AbstractCriteria firstCriteria;
	private AbstractCriteria secondCriteria;

	public AndCriteria(Criteria firstCriteria, Criteria other) {
		this.firstCriteria = (AbstractCriteria)firstCriteria;
		this.secondCriteria = (AbstractCriteria)other;
	}

	@Override
	boolean matches(Task task) {
		return firstCriteria.matches(task) && secondCriteria.matches(task);
	}
}