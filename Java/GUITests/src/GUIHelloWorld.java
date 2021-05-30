

import javafx.application.Application;
import javafx.stage.Stage;
//import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class GUIHelloWorld extends Application
{
	public static void main(String[] args)
	{
		launch(args);
	}

	
	@Override
	public void start(Stage window) throws Exception
	{
		VBox layout = new VBox(30);
		Scene scene = new Scene(layout, 300, 300);
		Label label = new Label();
		Button exitButton = new Button();
		
		window.setTitle("Hello World !");
		label.setText("Hello, World!");
		exitButton.setText("Exit");
		exitButton.setOnAction(e -> window.close());
		
		layout.getChildren().addAll(exitButton, label);
		window.setScene(scene);
		
		window.show();
	}
}






