import java.util.Scanner;

public class CollatzConjecture 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		System.out.println("Type number>: ");
		int num = input.nextInt();
		input.close();
		
		int i = 0;
		while(num != 1){
			if(num%2 == 0)
				num/=2;
			else
				num = num*3+1;
			
			if(i%10 == 0){
				System.out.println();
				//i = 0;
			}
			++i;
			System.out.printf("%d\t", num);
		}
		System.exit(0);
	}
}

