public class TestClass
{
	public static void main(String[] args)
	{
		Point2D point0 = null, point1 = null;
		Point3D point2 = null, point3 = null;
		
		if(args.length == 4){
			int p0X = Integer.parseInt(args[0]), p0Y = Integer.parseInt(args[1]); // 2D point #1
			int p1X = Integer.parseInt(args[2]), p1Y = Integer.parseInt(args[3]); // 2D point #2
			
			point0 = new Point2D(p0X, p0Y);
			point1 = new Point2D(p1X, p1Y);
			
			point0.printInfo(point0);
			point1.printInfo(point1);
			System.out.println("Distance: " + point0.calculateDistance(point1));
			System.out.println();
		}
		else if(args.length == 6){   
			int p0X = Integer.parseInt(args[0]), p0Y = Integer.parseInt(args[1]), p0Z = Integer.parseInt(args[2]); // 3D point #1
			int p1X = Integer.parseInt(args[3]), p1Y = Integer.parseInt(args[4]), p1Z = Integer.parseInt(args[5]); // 3D point #2
			
			point2 = new Point3D(p0X, p0Y, p0Z);
			point3 = new Point3D(p1X, p1Y, p1Z);
			
			point2.printInfo(point2);
			point3.printInfo(point3);
			System.out.println("Dinstace: " + point2.calculateDistance(point3));
			System.out.println();
		}
		else if(args.length < 4)
			System.out.println("Error: too few arguments !");
		else if(args.length > 6)
			System.out.println("Error: too many arguments !");
		else
			System.out.println("Error: invalid number of arguments !");
	}
}

