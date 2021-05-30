package it.claudiopisa.ConfirmBox;

import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class ConfirmBox
{
	private static String title;
	private static String message;
	private static Stage window;
	private static Scene scene;
	private static StackPane layout;
	private static boolean answer;
	
	
	public static boolean displayConfirmBox(String titleInput, String messageInput)
	{
		window = new Stage();
		layout = new StackPane();
		scene = new Scene(layout, 250, 300);
		title = titleInput;
		message = messageInput;
		Button allow = new Button("Yes");
		Button deny = new Button("No");
		Label label = new Label(message);
		
		layout.getChildren().addAll(allow, deny, label);
		allow.setOnAction(e -> {
			answer = true;
			window.close();
		});
		deny.setOnAction(e -> {
			answer = false;
			window.close();
		});
		allow.setTranslateX(-16.3);
		deny.setTranslateX(16.3);
		label.setTranslateY(-30);
		window.initModality(Modality.APPLICATION_MODAL);
		window.setTitle(title);
		window.setScene(scene);
		
		window.showAndWait();
		
		return answer;
	}
}
