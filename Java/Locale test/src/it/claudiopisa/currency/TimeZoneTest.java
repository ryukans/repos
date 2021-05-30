package it.claudiopisa.currency;

import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.TimeZone;

public class TimeZoneTest
{
	public static void main(String[] args)
	{
		Calendar cal = new GregorianCalendar(TimeZone.getTimeZone("America/New_York"));
		int USTime = cal.get(Calendar.HOUR_OF_DAY); 
		
		cal = new GregorianCalendar(TimeZone.getTimeZone("Europe/Rome"));
		int ItalyTime = cal.get(Calendar.HOUR_OF_DAY);
		
		System.out.println("Time at New York: " + USTime);
		System.out.println("Time at Rome: " + ItalyTime);
		System.out.println("\n\nAll available lables: \n");
	
		String[] s = TimeZone.getAvailableIDs();
		for (int i = 0; i < s.length; i++) {
			System.out.println(s[i]);
		}
	}
}
