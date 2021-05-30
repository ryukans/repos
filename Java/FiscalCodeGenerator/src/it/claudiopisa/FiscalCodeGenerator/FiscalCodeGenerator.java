package it.claudiopisa.FiscalCodeGenerator;

import java.io.IOException;
import java.util.Scanner;

@SuppressWarnings("unused")
public class FiscalCodeGenerator 
{
	public static void main(String[] args) 
	{
		FiscalCode fc = new FiscalCode("CLAUDIO", "PISA", 'M', "02/09/1998");
		
		// These statements below are used only for debug tests
		/*char c = '\u0000';
		c = fc.getChar(c);*/
		
		fc.setFiscalCode();
		System.out.print(fc.getFiscalCode());
		
		System.exit(0);
	}
}


class FiscalCode
{	
	private final int MAX_LETTERS = 3;
	private int totalLetters;
	private String letters, fiscalCode, name, lastName, birthDate;
	private char sex;
	
	public FiscalCode(String name, String lastName, char sex, String birthDate)
	{
		setLastName(lastName);
		setName(name);
		setSex(sex);
		setBirthDate(birthDate);
		
	}
	//TODO uppercase converter method
	
	public void setFiscalCode()
	{ this.fiscalCode = lastName + name; }
	
	public String getFiscalCode()
	{ return fiscalCode; }
	
	
	private void setName(String name)
	{
		if(name == null || name == "")
			System.out.println("No name has been given !");
		
		totalLetters = 0;
		letters = "";

		pickConsonants(name);
		
		if(totalLetters == MAX_LETTERS+1)
			this.name = "" + letters.charAt(0) + letters.charAt(2) + letters.charAt(3);
		
		else if(totalLetters < MAX_LETTERS){
			pickWovels(name);
			if(totalLetters < MAX_LETTERS)
				fillWithX(name);
			this.name = "" + letters.charAt(0) + letters.charAt(1) + letters.charAt(2);
		}
		else // Normal case (3 consonants)
			this.name = "" + letters.charAt(0) + letters.charAt(1) + letters.charAt(2);
	}
	
	
	private void setLastName(String lastName)
	{
		if(lastName == null || lastName == "")
			System.out.println("No last name has been specified !");
		
		totalLetters = 0;
		letters = "";

		pickConsonants(lastName);

		if(totalLetters < MAX_LETTERS){
			pickWovels(lastName);
			if(totalLetters < MAX_LETTERS)
				fillWithX(lastName);
		}
		this.lastName = "" + letters.charAt(0) + letters.charAt(1) + letters.charAt(2);
	}

	
	private void setSex(char sex)
	{
		if((sex != 'M' || sex != 'm') 
		|| (sex != 'F' || sex != 'f'))
			System.out.println("Sex type not vadlid !");
		else if(sex == '\u0000')
			System.out.println("Sex not specified !");
		else
			this.sex = sex;
	}
	
	
	private void setBirthDate(String birthDate)
	{
		if(birthDate == null || birthDate == "")
			System.out.println("Birth date not specified !");
		else{
			setYear(birthDate.substring(6, 10));
			setMounth(birthDate.substring(3, 5));
			setDay(birthDate.substring(0, 2));
		}
	}
	
	
	
	private void setYear(String year)
	{}
	
	
	private void setMounth(String mounth)
	{}
	
	
	private void setDay(String day)
	{}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	private void pickConsonants(String string)
	{
		int i;

		i = 0;
		while(totalLetters < MAX_LETTERS+1 && i < string.length()){
			if(isConsonant(string.charAt(i))){
				letters += string.charAt(i);
				++totalLetters;
			}
			++i;
		}
	}
	
	
	private void pickWovels(String string)
	{
		int i;

		i = 0;
		while(totalLetters < MAX_LETTERS && i < string.length()){
			if(isWovel(string.charAt(i))){
				letters += string.charAt(i);
				++totalLetters;
			}
			++i;
		}
	}
	
	
	private void fillWithX(String string)
	{
		while(totalLetters < MAX_LETTERS){
			letters += 'X';
			++totalLetters;
		}
	}
	
	

	/**
	 * 
	 * @param <b>c</b>
	 * @return <b>true</b> if it is a wovel
	 * @return <b>false</b> if it is not a wovel
	 * 
	 * The method handles both uppercase and lowercase letters
	 */
	public boolean isConsonant(char c) { 
		return (!isWovel(c));
	}
	
	/**
	 * 
	 * @param <b>c</b>
	 * @return <b>true</b> if it is a consonant
	 * @return <b>false</b> if it is not a consonant
	 * 
	 * The method handles both uppercase and lowercase letters
	 */
	public boolean isWovel(char c)
	{ 
		return ((c == 'A' || c == 'a') 
			 || (c == 'E' || c == 'e') 
			 || (c == 'I' || c == 'i') 
			 || (c == 'O' || c == 'o')
			 || (c == 'U' || c == 'u')); 
	}
	
	
	
	
	
	public char getChar(char c)
	{
		try{
			c = (char) System.in.read();
		} 
		catch(IOException e){
			e.printStackTrace();
		}
		
		return c;
	}
	
}





/*	i = numLetters = 0;
while(numLetters < MAX_LETTERS+1 && i < name.length()){
	if(isConsonant(name.charAt(i))){
		letters += name.charAt(i);
		++numLetters;
	}
	++i;
}


if(numLetters == MAX_LETTERS+1)
	this.name = "" + letters.charAt(0) + letters.charAt(2) + letters.charAt(3);


else if(numLetters < MAX_LETTERS){
	i = 0;
	while(i < name.length()){
		if(isWovel(name.charAt(i))){
			letters += name.charAt(i);
			++numLetters;
		}
		++i;
	}
	while(numLetters < MAX_LETTERS){
		letters += 'X';
		++numLetters;
	}
}
this.name = "" + letters.charAt(0) + letters.charAt(1) + letters.charAt(2); */

/*
public boolean isConsonantOrWovel(char c)
{
	if(((c >= 'A' && c <= 'Z') 
	    	&& c != 'A' 
	    	&& c != 'E' 
	    	&& c != 'I' 
	    	&& c != 'O' 
	    	&& c != 'U')
		|| 
		((c >= 'a' && c <= 'z')
			&& c!= 'a'
			&& c!= 'e'
			&& c!= 'i'
			&& c!= 'o'
			&& c!= 'u')
	  ){ return true; }
	
	else{ return false; }
}
*/
