import java.util.Random;

public class Race 
{
		final int MAX_TEAMS = 5;
		private String raceName;
		private String outcome;
		private Team[] team = new Team[MAX_TEAMS];
	
		public Race(String raceName)
		{ 
			setRaceName(raceName);
			System.out.println(getRaceName());
			setTeams();
			getTeams();
		}
	
	
		public void setRaceName(String raceName)
		{ this.raceName = raceName; }
	
	
		public String getRaceName()
		{ return raceName; }
	
	
		public void  setOutcome(Team winner)
		{ this.outcome = "The winner is " +  winner.getDriver().getDriverName() + 
									" running for " + winner.getVehicle().getVehicleName(); }

	
		String getOutcome(String winner)
		{ return outcome; }
	
 
		@SuppressWarnings("unused")
		public void setTeams()
		{
			Driver driverOne, dirverTwo, driverThree, driverFour, driverFive;
			Vehicle V0, V1, V2, V3, V4, V5;
			Team teamOne, teamTwo, teamThree, teamFour, teamFive;
		
			team[0] = teamOne = new Team(V0 = new Vehicle("Ferrari"), driverOne = new Driver("Sciumacher"));
			team[1] = teamTwo = new Team(V1 = new Vehicle("Mercedes"), dirverTwo = new Driver("Hamilton"));
			team[2] = teamThree = new Team(V2 = new Vehicle("McLaren"), driverThree = new Driver("Alonso"));
			team[3] = teamFour = new Team(V3 = new Vehicle("RedBull"), driverFour = new Driver("Ricciardo"));
			team[4] = teamFive = new Team(V4 = new Vehicle("Sauber"), driverFive = new Driver("Ericsson"));
		}
	
	
		public void getTeams()
		{
			try
			{ Thread.sleep(800); } 
			catch(InterruptedException ex)
			{ Thread.currentThread().interrupt(); }
		
			System.out.println("Teams:");
			for(int i = 0; i < MAX_TEAMS; i++)
				System.out.println(team[i].getDriver().getDriverName() + " - " 
							+ team[i].getVehicle().getVehicleName());
		}
	
	
		public void startRace()
		{
			Random rand = new Random();
			Team winner = team[rand.nextInt(5)];
			countdown();
			setOutcome(winner);
			System.out.print(getOutcome(outcome));
		}
	
	
		private void countdown()
		{
			for(int n = 3; n > 0; n--){
				try 
					{ Thread.sleep(1000); } 
				catch(InterruptedException ex)
					{ Thread.currentThread().interrupt(); }
			
				System.out.println(n);
			} // end of former for loop
		
			System.out.print("GO!\n\nRunning race");
			for(int n = 3; n > 0; n--){
				try 
					{ Thread.sleep(1000); }
				catch(InterruptedException ex)
					{ Thread.currentThread().interrupt(); }
			
				System.out.print(" . ");
			} // end of latter for loop
		}
}
