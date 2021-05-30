package printIndex;

import java.util.Scanner;

public class printIndex 
{

	public static void main(String args[]) 
	{
		
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		System.out.print("Type something\n>:");
		String sentence = input.nextLine();
		System.out.printf("\n\nCourrent sentence\n>: %s\n\n", sentence);
		
		Util ogg = new Util();
		
		System.out.print("What character do you want to display ?\n>:");
		int index = input.nextInt();
		char ch = ogg.getIndex(sentence, index);
		System.out.printf("\n\n>:%c", ch);
		input.close();
		
	}

}
