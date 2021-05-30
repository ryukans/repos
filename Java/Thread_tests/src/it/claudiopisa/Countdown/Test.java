package it.claudiopisa.Countdown;

public class Test 
{
	public static void main(String[] args)
	{
		try {
			Countdown countdown = new Countdown("Countdown", 5, 800L);
			countdown.getCountdown();
			System.out.println("GO !");
		} 
		catch (CountdownException e) {
			System.out.println(e);
		}
		
	}
}
