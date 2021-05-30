package it.claudiopisa.ConfirmBox;

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
	{
		launch(args);
	}

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
		button.setOnAction(e -> {
			Stage tmpWindow = new Stage();
			StackPane tmpLayout = new StackPane();
			Scene tmpScene = new Scene(tmpLayout, 150, 150);
			Button tmpExitButton = new Button("Close");
			Label tmpLabel = new Label();
			
			tmpExitButton.setOnAction(e_ -> tmpWindow.close());
			tmpExitButton.setTranslateY(-20);
			tmpWindow.setOnCloseRequest(e_-> tmpWindow.close());
			
			boolean answer = ConfirmBox.displayConfirmBox("Confirm Box", "Y/N");
			
			if (answer) {
				tmpLabel.setText("You clicked YES");
				tmpLabel.setTranslateY(-40);
				tmpLayout.getChildren().addAll(tmpExitButton, tmpLabel);
				tmpWindow.setScene(tmpScene);
				tmpWindow.show();
				
			}
			else {
				window.close();
			}
		});
		exitButton.setOnAction(e -> closeProgram());
		exitButton.setTranslateY(30);
		label.setTranslateY(-50);
		
		window.setScene(scene);
		window.setTitle("Confirm box test");
		window.setOnCloseRequest(e -> {
			e.consume();
			closeProgram();
		});
		window.show();
	
	}
	
	private void closeProgram()
	{
		boolean answer = ConfirmBox.displayConfirmBox("Exit", "R u sure u want to exit ?");
		if (answer)
			window.close();
	}

}





