package arrayLenght;

import java.util.Scanner;

public class Util 
{
	
	public void getLine(char line[], int size)
	{
		try (Scanner input = new Scanner(System.in)) {
			int i = 0;
			char c = 0;
			while(i < size && (c = input.next().charAt(i)) != '\n') {
				line[i++] = c;
			}
			line[i] = '\0';
		}
	}
	
	
	public int getLenght(char line[])
	{
		int i = 0;
		while(line[i++] != '\0');
		return i;
		}
	
}
