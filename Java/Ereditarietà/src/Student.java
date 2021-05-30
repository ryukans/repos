public class Student extends Person
{
	private int serialNumber, numberExams;

	public Student(
			String name, 
			String lastName, 
			int age, 
			int serialNumber, 
			int numberExams) 
	{
		/* In case you want to use the parameterized method: */
		super(name, lastName, age);
		 
		
		/* In case you want to use the default constructor method:
		 * setName(name);
		 * setLastName(lastName);
		 * setAge(age); 
		 */
		
		/* In case the Person class' variables are public:
		 * super.name = name;
		 * super.lastName = lastName;
		 * super.age = age;
		 */
		
		setSerialNumber(serialNumber);
		setNumberExams(numberExams);
	}


	public void setSerialNumber(int serialNumber)
	{ this.serialNumber = serialNumber; }
	
	public int getSerialNumber()
	{ return serialNumber; }
	
	
	public void setNumberExams(int numberExams)
	{ this.numberExams = numberExams; }
	
	public int getNumberExams()
	{ return numberExams; }


	public String viewStudentDetails()
	{ return String.format("%s\nExams:\t%d\nSerial number:\t%d ", viewPersonDetails(), numberExams, serialNumber); }
}


