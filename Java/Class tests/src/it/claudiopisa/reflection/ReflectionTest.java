package it.claudiopisa.reflection;

import java.lang.reflect.*; 

public class ReflectionTest
{
	public static void main(String[] args)
	{
		String className = "java.lang.String";
		Class<?> objectClass = null;
		
		
		try {
			objectClass = Class.forName(className);
		}
		catch (Exception exc) {
			exc.printStackTrace();
		}
		
		Method[] methods = objectClass.getMethods();
		
		for (int i = 0; i < methods.length; i++) {
			String 		name = methods[i].getName();
			Class<?>[]	classParameters = methods[i].getParameterTypes();
			String		stringClassParameters = "";
			
			for (int j = 0; j < classParameters.length; ++j)
				stringClassParameters += classParameters[j].toString()
					+ (j+1 < classParameters.length ? ", " : "");
			
			String methodReturnType = methods[i].getReturnType().getName();
			String method = methodReturnType + " " + name + "(" + stringClassParameters + ")";
			System.out.println(method);
		}
	}
	
}
