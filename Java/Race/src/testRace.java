import java.io.IOException;

public class testRace 
{

	public static void main(String[] args)
	{
		int c = 0;
		
		while (true) {
			Race Monza = new Race("F1 - Monza\n");
			Monza.startRace();
			
			System.out.println("\nAgain ?\n\n.Any key to continue\n.Esc to exit");
/*
			c = input.next().charAt(0);
			if(c == ' ')
				break;
			else
				System.out.println("\n");*/
			
			try
			{ c = System.in.read(); } 
			catch(IOException exc)
			{ exc.printStackTrace(); }
			
			if (c == ' ')
				Monza.startRace();
			else
				System.exit(0);
		}
	}
		
}


