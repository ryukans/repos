import java.util.Scanner;

public class PowersCalculations
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int base, exp, power, max, num;
		
		System.out.print("Type number>: ");
		num = input.nextInt();
		System.out.print("Type base>: ");
		base = input.nextInt();
		input.close();
		
		exp = 1;
		power = max = 0;
		while(power < num){
			power = (int) Math.pow(base, exp++);
			if(num%power == 0)
				max = power;
		}
		
		while (num%base == 0) {
		    num/=2;
		    exp++;
		}
		
		System.out.printf("%d is divisible by the max power of %d^%d", num, base, (int) (Math.log(max)/Math.log(2)));
	}
}

