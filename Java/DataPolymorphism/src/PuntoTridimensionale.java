public class PuntoTridimensionale extends Punto
{
	private int z;
	
	public void setZ(int z)
	{
		this.z = z;
	}
	
	public int getZ()
	{
		return z;
	}
	
	
	public double distanzaDallOrigine()
	{
		int tmp = (getX()*getX()) + (getY()*getY()) + (z*z); // N.B. : x ed y non sono ereditate
		return Math.sqrt(tmp);
	}
}

