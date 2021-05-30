package com.ekansFox.RandString;
import java.util.Random;

public class Rand
{
	public int getRandRange(int min, int max)
	{
		Random rand = new Random();
		@SuppressWarnings("unused")
		int randNum;
		
		return randNum = (rand.nextInt(max-min+1)+min);
	}
}
