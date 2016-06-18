package org.elsys.todo.impl;


import java.util.Arrays;
import java.util.List;

import org.elsys.todo.Criteria;
import org.elsys.todo.Task;

public class TagsCriteria extends AbstractCriteria implements Criteria {

	List<String> tags;
	
	public TagsCriteria(String[] tags) {
		this.tags = Arrays.asList(tags);
	}
	
	/*@Override
	boolean matches(Task task) {
		for (int i = 0; i < this.tags.length; i++) {
			boolean found = false;
			for (int j = 0; j < task.getTags().length; j++) {
				if (task.getTags()[j].equals(this.tags[i])) {
					found = true;
					break;
				}
			}
			
			if (!found) {
				return false;
			}
		}
		
		return true;
	}*/
	
	@Override
	boolean matches(Task task) {
		List<String> taskTags = Arrays.asList(task.getTags());
		for	(String tag: this.tags) {
			if (taskTags.indexOf("tv shows") < 0) {
				return false;
			}
		}
		
		return true;
	}
	
	public String[] getTags() {
		return (String[]) this.tags.toArray();
	}
}
