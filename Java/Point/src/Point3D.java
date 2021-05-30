public class Point3D extends Point2D
{
	private int z;
	
	public Point3D(int x, int y, int z)
	{ setXYZ(x, y, z); }
	
	
	public void setZ(int z)
	{ this.z = z; }
	
	public int getZ()
	{ return z; }
	
	
	public void setXYZ(int x, int y, int z)
	{
		setXY(x, y); //re-use
		setZ(z);
	}
	
	@Override
	public double calculateDistance(Point2D p)
	{
		if(p instanceof Point3D) { return this.calculateDistance((Point3D) p); }
		else { return -1; } // non valid distance
	}
	
	/*
	@Override
	public double calculateDistance(Point2D p)
	{
		if (p instanceof Point3D) {
			Point3D p3D = (Point3D) p;
			
			int x1 = getX(), y1 = getY(), z1 = getZ();
			int x2 = p3D.getX(), y2 = p3D.getY(), z2 = p3D.getZ();
			int sqrX = (x1 - x2)*(x1 - x2), sqrY = (y1 - y2)*(y1 - y2), sqrZ = (z1 - z2)*(z1 - z2);
			
			return Math.sqrt(sqrX + sqrY + sqrZ);
		}
		else
			return -1;
	}
	*/
	
	//Overload
	private double calculateDistance(Point3D p)
	{
		int x1 = getX(), y1 = getY(), z1 = getZ();
		int x2 = p.getX(), y2 = p.getY(), z2 = p.getZ();
		int sqrX = (x1 - x2)*(x1 - x2), sqrY = (y1 - y2)*(y1 - y2), sqrZ = (z1 - z2)*(z1 - z2);
		
		return Math.sqrt(sqrX + sqrY + sqrZ);
	}

	
	public String toString()
	{ return String.format("X:_ %d\tY:_ %d\tZ:_ %d", getX(), getY(), getZ()); }
}

