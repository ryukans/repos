public class NullFinder 
{

	public static void main(String args[]) 
	{

		char line[] = new char[100];
		int i;
		line[0] = 'H';
		line[1] = 'e';
		line[2] = 'l';
		line[3] = 'l';
		line[4] = 'o';
		
		i = 0;
		while(line[++i] != '\u0000');
		System.out.println("Found at index " + i);

		i = 0;
		while(line[i] != '\u0000')
			System.out.printf("%c\n", line[i++]);
		
	}

}
