package APG;
import java.util.*;

public class APG
{
	
	public static void main(String args[]) 
	{	
		
		final int MAX_SIZE = 24;
		Scanner input = new Scanner(System.in);
		Random rand = new Random();
		Util utl = new Util();
		char password[] = new char[MAX_SIZE];
		String charSet = ""
				+ "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz" //Letters (Aa-Zz)
				+ "0123456789"											 //Numbers (0-9)
				+ "!@#$%^&*()_+-={},./\\<>?`~[]|;:\"";                   //Symbols 
		

		System.out.print("How many times do you want to generate a password ?\n>: ");
		int times = input.nextInt();
		System.out.print("\n\n1. Display only\n2. Write on a file\n> ");
		char answer = input.next().charAt(0);
		input.close();

		
		if(times == 0){
			System.out.print("End.");
			System.exit(0);
		}
		else{
			System.out.println("\nCreation of password/s");
			for(int j = 0, k = 1; j < times; j++, k++){
				for(int i = 0; i < MAX_SIZE; i++){
					int randIndex = rand.nextInt(charSet.length());
					password[i] = charSet.charAt(randIndex);
				}
				if(answer == '1')
					System.out.printf("\n%d|\t %s\n", k, utl.arrayToString(password));
				else
					utl.arrayToFile(password, k);
			}
		}
		System.exit(0); //Runtime.getRuntime().exit(0);
		
	}
	
}