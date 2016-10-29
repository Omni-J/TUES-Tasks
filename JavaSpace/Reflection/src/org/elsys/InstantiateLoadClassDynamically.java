package org.elsys;

public class InstantiateLoadClassDynamically {
	public Class load(String name){
		Class.forname(name);
	}
}
