package org.elsys.smt;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

import org.junit.Test;

public class EqualsAndHashTest {

	@Test
	public void testOperatorEquals() {
		Name n1 = new Name("pesho", "ivanov");
		Name n2 = new Name("pesho", "ivanov");
		
		assertFalse(n1 == n2);
		assertTrue(n1.equals(n2));
	}
	@Test
	public void testStringEquals() {
		assertTrue("pesho".equals("pesho"));
		assertTrue("pesho" == "pesho");
		String pesho = new String("pesho");
		assertFalse(pesho == "pesho");
		assertTrue(pesho.equals("pesho"));
	}
	
	@Test
	public void testLisCointains(){
		ArrayList<Name> names = new ArrayList<>();
		names.add(new Name("mitko", "petrov"));
		names.add(new Name("mitko", "petroff"));
		names.add(new Name("mitko", null));
	}

	@Test
	public void testAddObject(){
		Set<Name> names = new HashSet<>();
		names.add(new Name("mitko", "petrov"));
		names.add(new Name("mitko", "petroff"));
		names.add(new Name("mitko", null));
		
		assertTrue(names.contains(new Name("mitko", null)));
		
	}
}
