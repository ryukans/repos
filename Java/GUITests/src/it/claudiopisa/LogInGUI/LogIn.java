package it.claudiopisa.LogInGUI;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import it.claudiopisa.AlertWindow.AlertWindow;


public class LogIn extends Application
{
	private final String username = "ekansfox", password = "patriots";
	
	public static void main(String[] args)
	{ launch(args); }
	

	@Override
	public void start(Stage window) throws Exception
	{
		GridPane layout = new GridPane();
		Scene scene = new Scene(layout, 400, 300);
		Button exitButton = new Button("Cancel");
		Button logInButton = new Button("Log in");
		Label fieldUsername = new Label("Username");
		Label fieldPassword = new Label("Password");
		TextField usernameInput = new TextField();
		PasswordField passwordInput = new PasswordField();

		layout.setPadding(new Insets(90, 0, 0, 88));
		layout.setVgap(15);
		layout.setHgap(10);
		usernameInput.setPromptText("Type here");
		passwordInput.setPromptText("Type here");
		exitButton.setOnAction(e -> window.close());
		logInButton.setOnAction(e -> {
			if (fieldsMatch(usernameInput, passwordInput)) { 
				AlertWindow.displayAlertWindow("Success", "Log in successful");
				window.close();
			} else {
				AlertWindow.displayAlertWindow("Failure", "\t\t  Cannot log in\nUsername or password doesn't match");
			}
		});
		exitButton.setTranslateX(29.5);
		exitButton.setTranslateY(20);
		logInButton.setTranslateX(-59);
		logInButton.setTranslateY(20);
		GridPane.setConstraints(fieldUsername, 0, 0);
		GridPane.setConstraints(fieldPassword, 0, 1);
		GridPane.setConstraints(usernameInput, 1, 0);
		GridPane.setConstraints(passwordInput, 1, 1);
		GridPane.setConstraints(exitButton, 1, 2);
		GridPane.setConstraints(logInButton, 2, 2);
		layout.getChildren().addAll( 		/* Nodes are added here because before the input fields weren't initialized yet */
			exitButton,
			logInButton,
			fieldUsername, 
			fieldPassword, 
			usernameInput, 
			passwordInput
		); 						

		window.setTitle("Log in");
		window.setScene(scene);
		window.show();
	}
	
	private boolean fieldsMatch(TextField username, PasswordField password)
	{
		if (username.getText().equals(this.username) && password.getText().equals(this.password)) {
			return true;
		} else {
			return false;
		}
	}
}


