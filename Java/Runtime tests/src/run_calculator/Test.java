package run_calculator;

public class Test
{

	public static void main(String[] args)
	{
		Runtime r = Runtime.getRuntime();
		
		try {
			r.exec("calc");
		}
		catch (Exception exc) {
			exc.printStackTrace();
		}
		
		System.out.println(r.availableProcessors());
	}
}
