package org.elsys.todo.impl;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import org.elsys.todo.Criteria;
import org.elsys.todo.Priority;
import org.elsys.todo.Status;
import org.elsys.todo.Task;
import org.elsys.todo.TodoList;

public class TodoListImpl implements TodoList {

	private List<Task> tasks;

	public TodoListImpl(String input) {
		tasks = Arrays.stream(input.split("\n")).map(line -> {
			String[] args = Arrays.stream(line.split("\\|")).map(String::trim)
				.toArray(size -> new String[size]);
			return new TaskImpl(Status.valueOf(args[0].toUpperCase()),
					args[1], Priority.valueOf(args[2].toUpperCase()),
					args[3].split(", "));
		}).collect(Collectors.toList());
	}

	private TodoListImpl(List<Task> tasks) {
		this.tasks = tasks;
	}

	@Override
	public Boolean isCompleted() {
		return tasks.stream().allMatch(task -> task.getStatus() == Status.DONE);
	}

	@Override
	public Double percentageCompleted() {
		int completedTaskCount = 0;
		for	(int i = 0; i < this.tasks.size(); i++) {
			if (this.tasks.get(i).getStatus() == Status.DONE) {
				completedTaskCount++;
			}
		}
		

		return (double)(completedTaskCount / this.tasks.size() * 100);
	}

	@Override
	public List<Task> getTasks() {
		return tasks;
	}

	@Override
	public TodoList filter(Criteria criteria) {
		List<Task> filtered = null;
		try {
			AbstractCriteria internalCriteria = (AbstractCriteria) criteria;

			filtered = tasks.stream().filter(task -> internalCriteria.matches(task))
				.collect(Collectors.toList());
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}

		return new TodoListImpl(filtered);
	}

	@Override
	public TodoList join(TodoList other) {
		// TODO Auto-generated method stub
		return null;
	}

}
