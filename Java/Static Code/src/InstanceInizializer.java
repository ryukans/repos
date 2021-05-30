public class InstanceInizializer 
{
	private static int a;
	
	public InstanceInizializer() {
		a += 10;
		System.out.println("constructr output = " + a);
	}
	
	/* instance initializer or object initializer */
	{
		a = 10;
		System.out.println("instance block output = " + a);
	}
	
	
	static public void main(String[] args) 
	{
		@SuppressWarnings("unused")
		InstanceInizializer ogg = new InstanceInizializer();
		System.out.println("main output = " + InstanceInizializer.a);
	}
}
