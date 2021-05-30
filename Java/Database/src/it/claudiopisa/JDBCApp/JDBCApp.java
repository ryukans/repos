package it.claudiopisa.JDBCApp;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCApp 
{
	public static void main(String[] args)
	{
		try {
		// loading driver type 1 (bridge. jdbc-odbc)
			String driver = "sun.jdbc.odbc.JdbcOdbcDriver";
			Class.forName(driver);
		// creating a connection string
			String url = "jdbc:odbc:myDataSource";
		// Obtaining a connection w/ username and password
			Connection con = DriverManager.getConnection(url, "myUserName", "myPassword");
		// creating a Statement object to control the db
			Statement cmd = con.createStatement();
		// executing a query e storing the results inside a ResultSet object
			String query = "SELECT * FROM myTable";
			ResultSet res = cmd.executeQuery(query);
		// printing the results line by line
			while (res.next()) {
				System.out.println(res.getString("columnName1"));
				System.out.println(res.getString("columnName2"));
			}
			res.close();
			cmd.close();
			con.close();
			
			} catch (SQLException e) {
				e.printStackTrace();
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
			}
	}
}








