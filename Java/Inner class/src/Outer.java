public class Outer
{
	private String string = "outer";
	
	public class Inner
	{
		private String string = "inner";
		
		public void InnerMethod() 
		{
			System.out.println(Outer.this.string + " " + this.string);
		}
	}
} 