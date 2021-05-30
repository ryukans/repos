package com.cuintabi.banca.model;

import java.lang.reflect.Field;
import java.util.ArrayList;

class SQLBuilder {
	public static final String ESCAPE_VALUES = "§§§";
	public static final String ESCAPE_TYPES = "°°°";
	
	private SQLBuilder() {}
	
	protected static <T extends Entita> String costruisciSQL(Class<T> TClass, T oggetto, TipoSQL tipoSQL, String... clausole) throws Exception {
		ArrayList<Field> campi = new ArrayList<Field>();
		ArrayList<Object> valori = new ArrayList<Object>();
		String SQL = "";
		
		for(Field campo : TClass.getFields())
			campi.add(campo);
		
		if(oggetto != null)
			for(int i = 0; i < campi.size(); i++) {
				String nomeCampo;
				if(campi.get(i).isAnnotationPresent(ForeignKey.class)) {
					nomeCampo = campi.get(i).getAnnotation(ForeignKey.class).tabella().getFields()[0].getName();
					valori.add(campi.get(i).getAnnotation(ForeignKey.class).tabella().getMethod("get" + nomeCampo.replace(nomeCampo.charAt(0), Character.toUpperCase(nomeCampo.charAt(0)))).invoke(oggetto));
				}
				else {
					nomeCampo = campi.get(i).getName();
					valori.add(oggetto.getClass().getMethod("get" + nomeCampo.replace(nomeCampo.charAt(0), Character.toUpperCase(nomeCampo.charAt(0)))).invoke(oggetto));
				}
			}
		
		if(tipoSQL == TipoSQL.INSERT) {
			SQL = "INSERT INTO " + TClass.getSimpleName() + " VALUES(";
			
			for(int i = 0; i < campi.size(); i++) {
				SQL += "?";
				if(campi.size() != i+1) SQL += ", ";
			}
			
			SQL += ");";
		}
		else if(tipoSQL == TipoSQL.SELECT) {
			SQL = "SELECT * FROM " + TClass.getSimpleName();
			
			if(clausole.length > 0) {
				SQL += " WHERE ";
				
				for(int i = 0; i < clausole.length; i++)
					SQL += clausole[i].split("=")[0] + " = ?" + (i != clausole.length-1 ? ", " : "");
			}
			
			SQL += ";";
		}
		else if(tipoSQL == TipoSQL.UPDATE) {
			if(clausole.length > 1) throw new Exception("Per eseguire un'operazione di SELECT devi specificare almeno una clausola.");
			
			SQL = "UPDATE " + TClass.getSimpleName() + " SET ";
			
			for(int i = 0; i < campi.size(); i++) {
				SQL += campi.get(i) + " = ?";
				if(campi.size() != i+1) SQL += ", ";
			}
			
			for(int i = 0; i < clausole.length; i++)
				SQL += " WHERE " + clausole[i].split("=")[0] + "= ?" + (i != clausole.length-1 ? ", " : "");
				
			SQL += ";";
		}
		else if(tipoSQL == TipoSQL.DELETE) {
			SQL = "DELETE FROM " + TClass.getSimpleName() + " WHERE ";
			
			for(int i = 0; i < campi.size(); i++)
				SQL += campi.get(i) + " = ?";
			
			SQL += ";";
		}
		
		SQL += ESCAPE_VALUES;
		if(!valori.isEmpty())
			for(int i = 0; i < valori.size(); i++)
				SQL += valori.get(i) + ESCAPE_TYPES + campi.get(i).getType().getSimpleName() + ESCAPE_VALUES;
		if(clausole.length > 0)
			for(int i = 0; i < clausole.length; i++)
				SQL += clausole[i].split("=")[1].replaceAll("'", "") + ESCAPE_TYPES + getTipoCampo(clausole[i], campi) + ESCAPE_VALUES;
		
		return SQL;
	}
	
	private static String getTipoCampo(String clausola, ArrayList<Field> campi) {
		for(Field campo : campi)
			if(campo.getName().equals(clausola.split("=")[1]))
				return campo.getType().getSimpleName();
		
		return null;
	}
	
	protected enum TipoSQL {
		INSERT, SELECT, UPDATE, DELETE;
	}
}