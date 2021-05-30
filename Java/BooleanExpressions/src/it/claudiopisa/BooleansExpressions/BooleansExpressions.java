package it.claudiopisa.BooleansExpressions;

public class BooleansExpressions 
{

	public static void main(String[] args) 
	{
		int i = 5;
		int j = ++i;
		int k = j++;
		int h = k--;
		boolean flag = ((i != j) && ((j <= k ) || (i <= h)));
		
		System.out.print(flag);
	}

}
