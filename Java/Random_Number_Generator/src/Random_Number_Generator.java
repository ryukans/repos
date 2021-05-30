import java.util.Scanner;

public class Random_Number_Generator 
{

	public static void main(String args[])
	{
		final int MAXSIZE = 1024;
		
		Scanner input = new Scanner(System.in);
		int times, range;
		int numbers[] = new int[MAXSIZE];
		
		System.out.printf("How many time do you want to generate a random number ?\n>: ");
		times = input.nextInt();
	
		System.out.printf("Type the range:\n>: ");
		range = input.nextInt();
		
		input.close();

		Rand.getRandInt(numbers, times, range);
		Rand.putRandInt(numbers, times);
		
		System.exit(0);
	}
}
