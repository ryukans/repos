public class StaticTest
{
	private static int a = 10;
	
	public StaticTest() {
		a += 10;
	}
	
	static { /* This will be the executed first */
		System.out.println("static block output = " + a);
	} 
	
	@SuppressWarnings("unused")
	public static void main(String[] args)
	{
		System.out.println("former main output = " + StaticTest.a);
		StaticTest ogg = new StaticTest();
		System.out.println("latter main output = " + StaticTest.a);
	}
}
