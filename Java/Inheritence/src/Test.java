public class Test
{

	public static void main(String[] args)
	{
		// I create a Animal object named genericAnimal
		Animal genericAnimal = new Animal();
		
		System.out.println(genericAnimal.getName());
		System.out.println(genericAnimal.getFood());
		
		// I create a Cat class like any other
		Cat cat0 = new Cat("Morris", "Tuna", "Rubber Mouse");
		
		// Print out the name, favFood and favToy
		System.out.println(cat0.getName());
		System.out.println(cat0.getFood());
		System.out.println(cat0.getToy());
		
		// You can also create classes based on the super class
		Animal cat1 = new Cat("Tabby", "Salmon", "Ball");
		
		// You pass objects like any other field
		acceptAnimal(cat1);
	}
	
	public static void acceptAnimal(Animal animal)
	{
		// Gets the name and favFood for the Animal passed
		System.out.println(animal.getName());
		System.out.println(animal.getFood());
		
		/* This is Polymorphism
		 * The interpreter automatically figures out what type
		 * of Animal it's dealing with and checks to make sure
		 * if methods were overwritten that they are called
		 * instead */
		animal.walkAround();
		
		/* The interpreter won't find anything that doesn't 
		 * originally exist in the Animal class however
		 * System.out.println(randAnimal.getToy()); Throws an ERROR */
		
		/* If you want access to fields or methods only found
		 * in the Cat class you have to cast the object to
		 * that specific class first */
		Cat tempCat = (Cat) animal;
		
		System.out.println(tempCat.getToy());
		
		// You could also cast the object directly like this
		System.out.println( ((Cat) animal).getToy() );
		
		/* You can use instanceof to check what type of object
		 * you have. This results in a positive for Animal 
		 * and for Cat */
		if (animal instanceof Cat)
		{
			System.out.println(animal.getName() + " is a Cat");
		}
	}
}

