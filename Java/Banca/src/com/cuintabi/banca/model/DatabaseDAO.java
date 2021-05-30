package com.cuintabi.banca.model;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import com.test.mypackage.MainCass.DataConnection;

public class DatabaseDAO <T extends Entita> {
	Boolean inserisci(T oggetto, Class<T> TClass) throws Exception {
		Connection conn = DataConnection.getConnection();
		String SQLGrezzo = SQLBuilder.costruisciSQL(TClass, oggetto, SQLBuilder.TipoSQL.INSERT);
		
		ArrayList<String> values = new ArrayList<>(), types = new ArrayList<>();
		String [] escapedValues = SQLGrezzo.split(SQLBuilder.ESCAPE_VALUES);
		String [] escapedTypes = SQLGrezzo.split(SQLBuilder.ESCAPE_TYPES);
		
		for(int i = 1; i < escapedValues.length; i++) {
			values.add(escapedValues[i].split(SQLBuilder.ESCAPE_TYPES)[0]);
			types.add(escapedTypes[i].split(SQLBuilder.ESCAPE_VALUES)[0]);
		}
		
		PreparedStatement pstmt = conn.prepareStatement(escapedValues[0]);
		for(int i = 0; i < SQLGrezzo.split("?").length-1; i++) {
			if(types.get(i).equals("String")) pstmt.setString(i, types.get(i));
			else if(types.get(i).equals("Integer")) pstmt.setInt(i, Integer.parseInt(types.get(i)));
			else if(types.get(i).equals("Double")) pstmt.setDouble(i, Double.parseDouble(types.get(i)));
		}
		
		Boolean result = pstmt.execute();
		conn.close();
		
		return result;
	}
	
	T selezionaOggetto(Class<T> TClass, String... attributi) {
		return selezionaOggetto(TClass, 0, attributi); 
	}
	
	private T selezionaOggetto(Class<T> TClass, Integer row, String... attributi) {
		return null; //TODO fare metodo seleziona oggetto
	}
	
	ArrayList<T> selezionaOggetti(Class<T> TClass, String... attributi) {
		ArrayList<T> oggetti = new ArrayList<>();
		
		try {
			for(int i = 0; i == -1; i++)
				oggetti.add(selezionaOggetto(TClass, i, attributi));
		} catch(IndexOutOfBoundsException e) {}
		
		return oggetti;
	}
	
	Integer modificaOggetto(T oggetto, String clausola, Class<T> TClass) throws Exception {
		Connection conn = DataConnection.getConnection();
		String SQLGrezzo = SQLBuilder.costruisciSQL(TClass, oggetto, SQLBuilder.TipoSQL.UPDATE, clausola);
		
		ArrayList<String> values = new ArrayList<>(), types = new ArrayList<>();
		String [] escapedValues = SQLGrezzo.split(SQLBuilder.ESCAPE_VALUES);
		String [] escapedTypes = SQLGrezzo.split(SQLBuilder.ESCAPE_TYPES);
		
		for(int i = 1; i < escapedValues.length; i++) {
			values.add(escapedValues[i].split(SQLBuilder.ESCAPE_TYPES)[0]);
			types.add(escapedTypes[i].split(SQLBuilder.ESCAPE_VALUES)[0]);
		}
		
		PreparedStatement pstmt = conn.prepareStatement(escapedValues[0]);
		for(int i = 0; i < SQLGrezzo.split("?").length-1; i++) {
			if(types.get(i).equals("String")) pstmt.setString(i, types.get(i));
			else if(types.get(i).equals("Integer")) pstmt.setInt(i, Integer.parseInt(types.get(i)));
			else if(types.get(i).equals("Double")) pstmt.setDouble(i, Double.parseDouble(types.get(i)));
		}
		
		Integer result = pstmt.executeUpdate();
		conn.close();
		
		return result;
	}
	
	Boolean eliminaOggetto(T oggetto, Class<T> TClass) throws SQLException, Exception {
		Connection conn = DataConnection.getConnection();
		String SQLGrezzo = SQLBuilder.costruisciSQL(TClass, oggetto, SQLBuilder.TipoSQL.DELETE);
		
		ArrayList<String> values = new ArrayList<>(), types = new ArrayList<>();
		String [] escapedValues = SQLGrezzo.split(SQLBuilder.ESCAPE_VALUES);
		String [] escapedTypes = SQLGrezzo.split(SQLBuilder.ESCAPE_TYPES);
		
		for(int i = 1; i < escapedValues.length; i++) {
			values.add(escapedValues[i].split(SQLBuilder.ESCAPE_TYPES)[0]);
			types.add(escapedTypes[i].split(SQLBuilder.ESCAPE_VALUES)[0]);
		}
		
		PreparedStatement pstmt = conn.prepareStatement(escapedValues[0]);
		for(int i = 0; i < SQLGrezzo.split("?").length-1; i++) {
			if(types.get(i).equals("String")) pstmt.setString(i, types.get(i));
			else if(types.get(i).equals("Integer")) pstmt.setInt(i, Integer.parseInt(types.get(i)));
			else if(types.get(i).equals("Double")) pstmt.setDouble(i, Double.parseDouble(types.get(i)));
		}
		
		Boolean result = pstmt.execute();
		conn.close();
		
		return result;
	}
	
	Boolean eliminaOggetti(ArrayList<T> oggetti, Class<T> TClass) throws SQLException, Exception {
		Boolean result = true;
		
		for(T oggetto : oggetti)
			result = (!eliminaOggetto(oggetto, TClass) ? false : result);
		
		return result;
	}
}