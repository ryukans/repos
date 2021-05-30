package application;
	
import java.io.IOException;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;


public class Main extends Application
{
	private Stage primaryStage;
	
	public static void main(String[] args)
	{ launch(args); }
	
	
	@Override
	public void start(Stage primaryStage)
	{
		this.primaryStage = primaryStage;
		primaryStage.show();
		mainWindow();
	}
	
	
	public void mainWindow()
	{
		
		
		try{
			FXMLLoader loader = new FXMLLoader(Main.class.getResource("MainWindowView.fxml"));
			AnchorPane pane = loader.load();
			MainWindowController mainWindowController = new MainWindowController();
			Scene scene = new Scene(pane);
			primaryStage.setScene(scene);
			primaryStage.show();
		}
		catch (IOException e){ e.printStackTrace(); }
		
		
		
	}
}

