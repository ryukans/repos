package application;
	
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;


public class Main extends Application 
{
	public static void main(String[] args)
	{
		launch(args);
	}
	
	
	public void start(Stage primaryStage)
	{
		try {
			BorderPane layout = new BorderPane();
			Scene scene = new Scene(layout, 400, 400);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setScene(scene);
			primaryStage.show();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	
}
