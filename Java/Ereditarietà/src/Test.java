public class Test 
{
	public static void main(String[] args)
	{
		Student student0 = new Student("GianFranMarco", "PierEsposito", 5, 446827, 4);
		
		System.out.println("---\n");
		System.out.println('>' + student0.viewPersonDetails()); /* Invoke the method of the 'Person' class */
		System.out.println('>' + student0.viewStudentDetails()); /* Invoke the method of the 'Student' class */
		
		
		Person person0 = new Person("Pierpaolo", "Urgibaldo", 9);
		
		System.out.println("\n---\n");
		System.out.println('>' + person0.viewPersonDetails());
		
		
		Person person1 = new Student("Giustino", "Eustace", 7, 78622, 3);
		
		System.out.println("\n---\n");
		System.out.println('>' + person1.viewPersonDetails());
		
		System.exit(0);
	}
}

