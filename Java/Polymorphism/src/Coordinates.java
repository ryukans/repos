public class Coordinates
{
	public Points coordinates;
		
	public Coordinates(Points coordinates)
	{ this.coordinates = coordinates; }
	
	public String toString()
	{ return String.format("%s", coordinates); }
}

