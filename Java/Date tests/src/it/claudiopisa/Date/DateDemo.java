package it.claudiopisa.Date;

import java.util.Date;
import java.text.SimpleDateFormat;

public class DateDemo
{
	public static void main(String[] args)
	{
		Date date = new Date();
		SimpleDateFormat df = new SimpleDateFormat("dd/mm/yyyy");
		System.out.println(date);
		System.out.println(df.format(date)); 
	}
}
