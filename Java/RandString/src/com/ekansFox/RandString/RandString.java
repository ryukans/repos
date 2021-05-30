package com.ekansFox.RandString;
import java.util.Scanner;

public class RandString
{

	public static void main(String[] args) 
	{
		Rand rand = new Rand();
		Scanner input = new Scanner(System.in);
		String word = "";
		int wordSize, randChar;
		
		System.out.print("Type word size>: ");
		wordSize = input.nextInt();
		input.close();
		
		for(int i = 0; i < wordSize; ++i){
			randChar = rand.getRandRange(97, 122);
			word+=(char) randChar;
		}

		System.out.print(word);
		
		System.exit(0);
	}
}

