import java.sql.*;

public class Test
{
    private static final String URL = "jdbc:mysql://localhost:3306/music";
    public static void main (String[] args)
    {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection connection = DriverManager.getConnection(URL, "root", "patriots");
            Statement stmt =  connection.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT Title, Artist, Genre FROM tracks");

            while (rs.next()) {
                System.out.format("%s - %s - %s%n", rs.getString(1), rs.getString(2), rs.getString(3));
            }
            connection.close();
            stmt.close();
            rs.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
