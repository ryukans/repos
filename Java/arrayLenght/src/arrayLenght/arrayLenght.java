package arrayLenght;

public class arrayLenght 
{

	public static void main(String args[]) 
	{
		
		final int MAXSIZE = 100;
		char line[] = new char [MAXSIZE];
		
		Util array = new Util();
		
		array.getLine(line, MAXSIZE);
		
		int lenght = array.getLenght(line);
		
		System.out.print(lenght);
		
	}

}
