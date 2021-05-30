package it.claudiopisa.currency;

import java.text.NumberFormat;
import java.util.Locale;

public class Test
{
	public static void main(String[] args)
	{
		double number = 55667788.12345;
		Locale localeUsa = Locale.US;
		Locale localeIta = Locale.ITALY;
		NumberFormat usaFormat = NumberFormat.getInstance(localeUsa);
		NumberFormat itaFormat = NumberFormat.getInstance(localeIta);
		String usaNumber = usaFormat.format(number);
		String itaNumber = itaFormat.format(number);
		
		System.out.println(localeUsa.getDisplayCountry() + " " + usaNumber);
		System.out.println(localeIta.getDisplayCountry() + " " + itaNumber); 
	}
}
