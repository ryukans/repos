import java.util.Random;

public class Rand
{
	private static Random randNumber = new Random();
	
	public static void getRandInt(int numbers[], int times, int range)
	{
		int i = 0;
		while(i < times)
			numbers[i++] = randNumber.nextInt(range+1);
	}
	
	public static void putRandInt(int numbers[], int times) 
	{
		System.out.printf("n°\tRandom Number\n%s\t%s\n", "--", "--------");
		
		int i = 0, label = 1;
		while(i < times)
			System.out.printf("%d|\t%d\n", label++, numbers[i++]);
	}
}

