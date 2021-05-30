package it.claudiopisa.ComboBox;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import it.claudiopisa.AlertWindow.AlertWindow;

public class Test extends Application 
{
	
	public static void main(String[] args) 
	{
		launch(args);
	}
	
	
	@Override
	public void start(Stage window) 
	{
		try {
			StackPane layout = new StackPane();
			Scene scene = new Scene(layout, 250, 200);
			ComboBox<String> comboBox = new ComboBox<String>();
			Button seeChoice = new Button("Ok");
			Button exitButton = new Button("Done");
			
			exitButton.setOnAction(e -> window.close());
			StackPane.setAlignment(exitButton, Pos.BOTTOM_RIGHT);
			exitButton.setTranslateX(-10);
			exitButton.setTranslateY(-10);
			seeChoice.setOnAction(e -> echoChoice(comboBox));
		/*	comboBox.setOnAction(e -> echoChoice(comboBox)); an alternative way to the previous statement */
			StackPane.setAlignment(seeChoice, Pos.BOTTOM_RIGHT);
			seeChoice.setTranslateX(-70);
			seeChoice.setTranslateY(-10);
			comboBox.getItems().addAll(
					"Appetite for Destruction",
					"Powerslave",
					"Dressed to Kill",
					"Black Album"
			);
			comboBox.setEditable(true);
			StackPane.setAlignment(comboBox, Pos.TOP_CENTER);
			comboBox.setTranslateY(20);
			comboBox.setPromptText("Choose album");
			layout.getChildren().addAll(comboBox, seeChoice, exitButton);
			
			window.setScene(scene);
			window.show();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void echoChoice(ComboBox<String> cb)
	{
		AlertWindow.displayAlertWindow("Your choice", cb.getValue() == null ? "You didn't select anything\n\tyou dumb asshole"
																			: "Your choice is " + cb.getValue(), 220, 190);
	}
}


