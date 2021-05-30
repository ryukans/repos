public class Person
{
	private String name;

	public Person(String name)
	{
		setName(name);
	}

	public void setName(String name)
	{	
		//TODO: check if string counains numbers; check if string has max 15 chars.
		if (name.isEmpty())
			System.out.println("Error -- name must be specified");
		else
			this.name = name.trim();
	}
	
	public String getName()
	{
		return this.name;
	}
}

