package it.claudiopisa.SwitchScene;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class Test extends Application
{
	@SuppressWarnings("unused")
	private Stage window;
	private Scene mainScene, secondScene;
	private VBox mainLayout;
	private HBox secondLayout;
	
	
	public static void main(String[] args)
	{
		launch(args);
	}

	
	@Override
	public void start(Stage window) throws Exception 
	{
		this.window = window;
		this.mainLayout = new VBox(50);
		this.mainScene = new Scene(mainLayout, 250, 250);
		Button switchButton0 = new Button("Switch layout");
		Button switchButton1 = new Button("Switch layout");
		
		mainLayout.getChildren().addAll(new Label("Main layout"), switchButton0);
		switchButton0.setOnAction(e -> window.setScene(secondScene));
		switchButton0.setTranslateY(-30);
		
		this.secondLayout = new HBox();
		this.secondScene = new Scene(secondLayout, 200, 200);
		
		secondLayout.getChildren().addAll(new Label("Second layout"), switchButton1);
		switchButton1.setOnAction(e -> window.setScene(mainScene));
		switchButton1.setTranslateX(20);
		
		window.setScene(mainScene);
		window.setTitle("Switch scene test");
		window.show();
	}
}
