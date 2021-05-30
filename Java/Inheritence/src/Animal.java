// Animal will act as a Super class for other Animals
public class Animal
{
	private String name = "Animal";
	private String favFood = "Food";
	
	//Default constructor (overwrites the other contstructor)
	public Animal()
	{ }
	
	public Animal(String name, String favFood)
	{
		this.name = name;
		this.favFood = favFood;
	}
	
	
	/* You use protected when you want to allow subclasses
	 * To be able to access methods or fields
	 * If you would have used private there would be no
	 * way for subclasses to call this method
	 * This is a final method which means it can't be overwritten */
	protected final void setName(String newName)
	{ this.name = newName; } // this is a reference to the object you're creating
	
	
	protected final String getName()
	{ return this.name; }
	
	
	public void eatStuff()
	{ System.out.println("Yum " + favFood); }
	
	
	public void walkAround()
	{ System.out.println(this.name + " walks around"); }
	
	
	public String getFood()
	{ return this.favFood; }
}

