package it.claudiopisa.Date;

import java.util.Date;
import java.util.Locale;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class DateFormatDemo
{
	public static void main(String[] args)
	{
		DateFormat formatter = new SimpleDateFormat("hh:mm:ss");
		String s = formatter.format(new Date());
		s = DateFormat.getTimeInstance(DateFormat.MEDIUM, Locale.ITALY).format(new Date());
		System.out.println(s); 
	}
}
