public class Test 
{
	public static void main(String[] args) 
	{
		Points points = new Points(10, 8, 4);
		
		System.out.println(points.toString());
		
		/**/
		
		Coordinates coo0 = new Coordinates(points);
		
		System.out.println(coo0.toString());
		
		System.out.println("\nCoordinates>: " + coo0);
		
		System.exit(0);
	}
}
