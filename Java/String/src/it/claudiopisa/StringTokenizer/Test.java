package it.claudiopisa.StringTokenizer;

import java.util.StringTokenizer;

public class Test
{
	public static void main(String[] args)
	{
		StringTokenizer st = new StringTokenizer("this, is a test string", ",");
		while (st.hasMoreTokens()) {
			System.out.println(st.nextToken());
		}
		
		System.out.println();
		
		StringTokenizer st2 = new StringTokenizer("this, is a test string", "t", true); //true: consider delimitator
		while (st2.hasMoreTokens()) {
			System.out.println(st2.nextToken());
		}
		
	}
}
