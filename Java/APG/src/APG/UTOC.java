package APG;
import java.util.*;

public class UTOC {
	

	public static void main(String[] args) 
	{
		
		Random rand = new Random();
		final int MAX_SIZE = 14;
		char password[] = new char[MAX_SIZE];
		
		
		for(int i = 0; i < MAX_SIZE; i++){
			password[i] = (char) rand.nextInt();
		}

		for(int i = 0; i < MAX_SIZE; i++){
			System.out.printf("%d",  password[i]);
		}

	}

}
