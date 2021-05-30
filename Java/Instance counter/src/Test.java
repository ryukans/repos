public class Test 
{
	public static void main(String[] args)
	{
		Counter ogg1 = new Counter();
		Counter ogg2 = new Counter();
		
		System.out.println(ogg1.getNumber() + " " + ogg2.getNumber());
		System.out.println(Counter.getTotalInstences());
	}
}


