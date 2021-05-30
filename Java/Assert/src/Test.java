public class Test 
{
	static {
		boolean assertsEnabled = false;
		assert assertsEnabled = true;
		if (!assertsEnabled)
			throw new RuntimeException("Asserts must be enabled! ");
	}
	
	public static void main(String[] args)
	{
		/* Design by contract */

		int b = 0;
		
		assert b > 0;
		assert b > 0: "The value is: " + b;
		assert b > 0: "assert b > 0 = " + (b > 0);
		
		if(!(b > 0)) {
			throw new AssertionError();
		}
		
		
	}
}
