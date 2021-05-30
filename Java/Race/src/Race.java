import java.io.IOException;
import java.util.Random;

public class Race 
{
	final int MAX_TEAMS = 6;
	private String raceName;
	private String outcome;
	private Team[] team = new Team[MAX_TEAMS];
	
	public Race(String raceName)
	{ 
		setRaceName(raceName);
		System.out.println(getRaceName());
		setTeams();
		getTeams();
		pause("\nPress any key to continue.");
	}
	
	
	public void setRaceName(String raceName)
	{ this.raceName = raceName; }
	
	public String getRaceName()
	{ return raceName; }
	
	
	private void setOutcome(Team winner)
	{ this.outcome = "The winner is " +  winner.getDriver().getDriverName() + " running for " + winner.getVehicle().getVehicleName() + '\n';}

	private String getOutcome(String winner)
	{ return outcome; }
	
 
	//@SuppressWarnings("unused")
	public void setTeams()
	{   /*
		Team teamOne, teamTwo, teamThree, teamFour, teamFive, teamSix;
		Vehicle v1, v2, v3, v4, v5, v6;
		Driver driver1, dirver2, driver3, driver4, driver5, driver6;
		
		team[0] = teamOne = new Team(v1 = new Vehicle("Ferrari"), driver1 = new Driver("Sciumacher"));
		team[1] = teamTwo = new Team(v2 = new Vehicle("Mercedes"), dirver2 = new Driver("Hamilton"));
		team[2] = teamThree = new Team(v3 = new Vehicle("McLaren"), driver3 = new Driver("Alonso"));
		team[3] = teamFour = new Team(v4 = new Vehicle("RedBull"), driver4 = new Driver("Ricciardo"));
		team[4] = teamFive = new Team(v5 = new Vehicle("Sauber"), driver5 = new Driver("Ericsson"));
		team[5] = teamSix = new Team(v6 = new Vehicle("Fiat 500"), driver6 = new Driver("Don Peppe"));
		*/
		
		team[0] = new Team(new Vehicle("Ferrari"), new Driver("Sciumacher"));
		team[1] = new Team(new Vehicle("Mercedes"), new Driver("Hamilton"));
		team[2] = new Team(new Vehicle("McLaren"), new Driver("Alonso"));
		team[3] = new Team(new Vehicle("RedBull"), new Driver("Ricciardo"));
		team[4] = new Team(new Vehicle("Sauber"), new Driver("Ericsson"));
		team[5] = new Team(new Vehicle("Fiat 500"), new Driver("Don Peppe"));
	}
	
	public void getTeams()
	{
		try
		{ Thread.sleep(800); } 
		catch(InterruptedException exc)
		{ Thread.currentThread().interrupt(); }
		
		System.out.println("Teams:");
		for(int teamNumber = 0; teamNumber < MAX_TEAMS; teamNumber++)
			System.out.println(team[teamNumber].getDriver().getDriverName() + " - " + team[teamNumber].getVehicle().getVehicleName());
	}
	
	
	public void startRace()
	{
		Random rand = new Random();
		Team winner = team[rand.nextInt(MAX_TEAMS)];
		countdown();
		setOutcome(winner);
		System.out.print(getOutcome(outcome));
	}
	

	private void countdown()
	{
		for(int n = 3; n > 0; n--){
			System.out.println(n);
			
			try 
			{ Thread.sleep(1000); } 
			catch(InterruptedException exc)
			{ Thread.currentThread().interrupt(); }
		}
		
		System.out.print("GO!\n\nRunning race");
		
		for(int n = 3; n > 0; --n){
			System.out.print(" . ");
			
			try 
			{ Thread.sleep(1000); }
			catch(InterruptedException exc)
			{ Thread.currentThread().interrupt(); }
		}
	}
	
	private void pause(String __msg)
	{
		System.out.println(__msg);
	
		try
		{ System.in.read(); } 
		catch(IOException exc)
		{ exc.printStackTrace(); }
	}
	
}

