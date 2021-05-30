public class Point2D
{
	private int x, y;
	
	public Point2D(int x, int y)
	{ setXY(x, y); } 
	
	public Point2D()
	{}
	
	
	public void setX(int x)
	{ this.x = x; }
	
	public int getX()
	{ return x; }
	
	
	public void setY(int y)
	{ this.y = y; }
	
	public int getY()
	{ return y; }
	
	
	public void setXY(int x, int y)
	{
		setX(x);
		setY(y);
	}
	
	
	public double calculateDistance(Point2D p)
	{
		int x1 = x, y1 = y;
		int x2 = p.getX(), y2 = p.getY();
		int sqrX = (x1 - x2)*(x1 - x2);
		int sqrY = (y1 - y2)*(y1 - y2);
		
		return Math.sqrt(sqrX + sqrY);
	}
	
	
	@Override
	public String toString()
	{ return String.format("X:_ %d\tY:_ %d", getX(), getY()); }
	
	
	public void printInfo(Point2D p)
	{
		if(p instanceof Point3D){ System.out.println("3D Point\n" + p); }
		else{ System.out.println("2D Point\n" + p); }
	}

}

