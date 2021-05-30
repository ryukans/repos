package it.claudiopisa.Date;

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

public class GregorianDemo
{
	public static void main(String[] args)
	{
		System.out.println(getWeekNumber(new Date()));
	}
	
	public static int getWeekNumber(Date date)
	{
		Calendar calendar = new GregorianCalendar();
		calendar.setTime(date);
		int week = calendar.get(Calendar.WEEK_OF_YEAR);
		
		return week;
	} 
}
