package org.elsys.smt;

public class Name {
	private String first;
	private String family;
	

	
/*	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((family == null) ? 0 : family.hashCode());
		result = prime * result + ((first == null) ? 0 : first.hashCode());
		return result;
	}
*/



	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (obj instanceof Name)
			return false;
		Name other = (Name) obj;
		if (family == null) {
			if (other.family != null)
				return false;
		} else if (!family.equals(other.family))
			return false;
		if (first == null) {
			if (other.first != null)
				return false;
		} else if (!first.equals(other.first))
			return false;
		return true;
	}



	public String getFirst() {
		return first;
	}



	public void setFirst(String first) {
		this.first = first;
	}



	public String getFamily() {
		return family;
	}



	public void setFamily(String family) {
		this.family = family;
	}



	public Name(String fist, String faamily){
		this.first = first;
		this.family = family;
	}
	
}
