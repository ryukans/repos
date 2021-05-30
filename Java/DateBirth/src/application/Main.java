package application;
	
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;


public class Main extends Application 
{
	public static void main(String[] args)
	{ launch(args); }
	
	
	@Override
	public void start(Stage window) 
	{
		try {
			Pane root = FXMLLoader.load(getClass().getResource("Interface.fxml"));
			Scene scene = new Scene(root, 400, 400);

			window.setScene(scene);
			window.show();
		} 
		catch(Exception exc) {
			exc.printStackTrace();
		}
	}
}
