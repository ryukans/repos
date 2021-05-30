public class Person 
{
	public String name, lastName;
	public int age;
	
	public Person(String name, String lastName, int age)
	{
		setName(name);
		setLastName(lastName);
		setAge(age);
	}
	
	//Default constructor method (overwrites the other constructor method)
	public Person()
	{ }
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName(){
		return name;
	}
	
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	
	public int getAge() {
		return age;
	}
	
	public String viewPersonDetails() {
		return String.format("%s\t%s\t%d\n", name, lastName, age);
	}
}


