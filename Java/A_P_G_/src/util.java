import java.util.Random;

public class util 
{
	Random randNumber = new Random();
	
	public int getRandNumber(int range)
	{
		int number = randNumber.nextInt(range);
		
		return number;
	}
}
