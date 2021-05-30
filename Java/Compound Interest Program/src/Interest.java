import java.util.Scanner;

public class Interest
{

	public static void main(String args[]) 
	{
		Scanner input = new Scanner(System.in);
		double amount, principal, rate;
		
		System.out.println("Principal>: ");
		principal = input.nextDouble();
		
		System.out.println("Rate>: ");
		rate = input.nextDouble();
		
		System.out.println("Day to start with>: ");
		int firstDay = input.nextInt();
		
		System.out.println("Last day>: ");
		int lastDay = input.nextInt();
		
		for(int i = firstDay; i <= lastDay; i++){
			amount = principal*Math.pow(1 + rate, i);
			System.out.printf("%d\t%d.5\n");
		}
		
		
	}

}
