//import java.util.Random;
//import java.util.Scanner;

public class A_P_G_ 
{

	public static void main(String args[]) 
	{
		
		final int LIMIT = 14; /*Password size*/
		
		
		//Scanner input = new Scanner(System.in);
		//Random randNumber = new Random();
		util random = new util();
		
		String charSet[] = {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789£$€&!?§<>^@#|=*+-/:"};
		String password[] = new String[LIMIT];
	    
		/*
	    System.out.println("How many times do you want to generate a password ?");
	    int times = input.nextInt();
	    input.close();*/
		int times = 1;
	    
	    int randIndex;
	    
	    

	    for(int j = 0; j < times; j++){
			for(int i = 0; i < LIMIT; i++){
				randIndex = random.getRandNumber(charSet.length);
				System.out.println(randIndex);
				password[i] = charSet[randIndex];
			}
	    }
	    
	    System.out.println(password);
	    
	}
	
}



