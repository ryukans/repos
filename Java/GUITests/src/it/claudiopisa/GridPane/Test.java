package it.claudiopisa.GridPane;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

@SuppressWarnings("unused")
public class Test extends Application
{
	
	private Stage window;
	private GridPane layout;
	private Scene scene;
	
	public static void main(String[] args)
	{
		launch(args);
	}
	

	@Override
	public void start(Stage window) throws Exception
	{
		this.window = window;
		this.layout = new GridPane();
		this.scene = new Scene(layout, 400, 300);
		Button logInButton = new Button("Log in");
		Label fieldUsername = new Label("Username");
		Label fieldPassword = new Label("Password");
		TextField usernameInput = new TextField();
		PasswordField passwordInput = new PasswordField();

		window.setTitle("GridPane test");
		layout.setPadding(new Insets(100, 0, 0, 100));
		layout.setVgap(10);
		layout.setHgap(10);
		usernameInput.setPromptText("Username");
		passwordInput.setPromptText("Password");
		GridPane.setConstraints(fieldUsername, 0, 0);
		GridPane.setConstraints(fieldPassword, 0, 1);
		GridPane.setConstraints(usernameInput, 1, 0);
		GridPane.setConstraints(passwordInput, 1, 1);
		GridPane.setConstraints(logInButton, 1, 2);
		layout.getChildren().addAll(logInButton, fieldUsername, fieldPassword, usernameInput, passwordInput); // Done here because before input fields weren't initialized yet

		window.setScene(scene);
		window.show();
	}
}



