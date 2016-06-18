package org.elsys.todo.test;
import org.junit.Assert;
import org.elsys.todo.impl.*;
import static org.junit.Assert.assertEquals;
import java.util.List;

import org.elsys.todo.Criteria;
import org.elsys.todo.Status;
import org.elsys.todo.Task;
import org.elsys.todo.TodoList;
import org.junit.Before;
import org.junit.Test;

public class TodoListImplTest {

	private TodoList todoList;
	
	@Before
	public void setUp() {
		this.todoList = TodoList.parse(
				"TODO    | Do OOP homework              | Low    | school, programming\n" + 
				"TODO    | Get 8 hours of sleep.        | Low    | health\n" + 
				"DOING   | Party hard.                  | Normal | social\n" + 
				"DONE    | Netflix and chill.           | Normal | tv shows\n" + 
				"TODO    | Find missing socks.          | Low    | meh");
	}
	
	@Test
	public void testAndCriteriaReturnsCorrectTask() {
		String[] tags = { "tv" };
		String[] andTags = { "shows" };
		TagsCriteria firstCriteria = (TagsCriteria) Criteria.tags(tags);
		TagsCriteria secondCriteria = (TagsCriteria) Criteria.tags(andTags);
		AndCriteria andCriteria = new AndCriteria(firstCriteria, secondCriteria);
		
		TodoList filtered = this.todoList.filter(firstCriteria);
		assertEquals(1, filtered.getTasks().size());
		
		//Task task = this.todoList.getTasks().get(4);
		//assertEquals(task, tasks.get(0));
	}

	@Test
	public void testPercentageCompleted() {
		int completedTaskCount = 0;
		for	(int i = 0; i < this.todoList.getTasks().size(); i++) {
			if (this.todoList.getTasks().get(i).getStatus() == Status.DONE) {
				completedTaskCount++;
			}
		}
		
		double reallyCompleted = completedTaskCount / this.todoList.getTasks().size() * 100;
		double completed = this.todoList.percentageCompleted();
		assertEquals(reallyCompleted, completed, 0.000001);
	}
	
	@Test
	public void testTagsCriteriaHasCorrectTags() {
		String[] tags = {
				"school",
				"programming"
		};
		
		TagsCriteria criteria = (TagsCriteria)Criteria.tags(tags);
		Assert.assertArrayEquals(tags, criteria.getTags());
	}

	@Test
	public void testFilter() {
		assertEquals(1,
				todoList.filter(Criteria.status(Status.DOING)).getTasks().size());
		assertEquals(1,
				todoList.filter(Criteria.status(Status.DONE)).getTasks().size());
		assertEquals(3,
				todoList.filter(Criteria.status(Status.TODO)).getTasks().size());
	}
}
