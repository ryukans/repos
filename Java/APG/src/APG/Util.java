package APG;
import java.io.PrintWriter;

public class Util 
{
	
	public String arrayToString(char line[])
	{
		String lineOutput = new String(line);
		
		return lineOutput;
	}
	
	
	public void arrayToFile(char line[], int index)
	{
		String lineOutput = new String(line);
		
		try{
			PrintWriter writer = new PrintWriter("PasswordTest.txt", "UTF-8");
			writer.println(index + "|\t" + lineOutput);
			writer.close();
		}
		catch(Exception exc){
			System.out.println("Error!");
			System.exit(0);
		}
		finally{
			System.out.println("Done!");
			System.exit(0);
		}
	}
	
}
