public class Team
{
	private Vehicle vehicle; 
	private Driver driver;
		
	public Team(Vehicle vehicle, Driver driver)
	{ 
		setVehicle(vehicle); 
		setDriver(driver);
	}
	
			
	public void setVehicle(Vehicle vehicle)
	{ this.vehicle = vehicle; }
		
	public Vehicle getVehicle()
	{ return vehicle; }
			
		
	public void setDriver(Driver driver)
	{ this.driver = driver; }
		
	public Driver getDriver()
	{ return driver; }
}
