public class Points 
{
	public int x, y, z;
	
	public Points(int x, int y, int z)
	{
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public String toString()
	{ return String.format(".%d.%d.%d.", x, y, z); }
}

