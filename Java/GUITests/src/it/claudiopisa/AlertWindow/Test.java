package it.claudiopisa.AlertWindow;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Test extends Application
{
	@SuppressWarnings("unused")
	private Stage window;
	private Scene scene;
	private StackPane layout;
	
	
	public static void main(String[] args)
    { launch(args); }


	@Override
	public void start(Stage window) throws Exception
	{
		this.window = window;
		this.layout = new StackPane();
		this.scene = new Scene(layout, 350, 350);
		Button button = new Button("Click here");
		Button exitButton = new Button("Exit");
		Label label = new Label("Main window");

		
		
		layout.getChildren().addAll(button, exitButton, label);
		button.setOnAction(e -> AlertWindow.displayAlertWindow("Alert Window", "This is an alert window"));
		label.setTranslateY(-50);
		exitButton.setOnAction(e -> window.close());
		exitButton.setTranslateY(30);
		
		window.setScene(scene);
		window.setTitle("Double window test");
		window.show();
	}
}