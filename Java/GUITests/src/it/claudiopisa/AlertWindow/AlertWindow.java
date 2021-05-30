package it.claudiopisa.AlertWindow;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Modality;
import javafx.stage.Stage;

@SuppressWarnings("unused")
public class AlertWindow 
{
	private static final String DEFAULT_WINDOW_TITLE = "Dialog Window";
	private static final String DEFAULT_BUTTON_TEXT = "Ok";
	private static final double DEFAULT_XAXIS = 250.55, DEFAULT_YAXIS = 200.55;
	private static double xAxis, yAxis;
	private static String title;
	private static String message;
	private static String buttonText;

	
	public static void displayAlertWindow(String titleIn, String messageIn)
	{
		Stage window = new Stage();
		StackPane layout = new StackPane();
		Scene scene = new Scene(layout, DEFAULT_XAXIS, DEFAULT_YAXIS);
		setWindowTitle(titleIn);
		setWindowMessage(messageIn);
		buttonText = DEFAULT_BUTTON_TEXT;
		Label label = new Label(message);
		Button exitButton = new Button(buttonText);
		
		label.setTranslateY(-50);
		exitButton.setOnAction(e -> window.close());
		exitButton.setTranslateY(10);
		exitButton.setMinSize(40, 25);
		layout.getChildren().addAll(label, exitButton);
		layout.setAlignment(Pos.CENTER);
		window.initModality(Modality.APPLICATION_MODAL);
		window.setTitle(title);
		window.setScene(scene);
		
		window.showAndWait();
	}

	
	public static void displayAlertWindow(String titleIn, String messageIn, double xAxisIn, double yAxisIn)
	{
		Stage window = new Stage();
		StackPane layout = new StackPane();
		Scene scene = new Scene(layout, xAxis = xAxisIn, yAxis = yAxisIn);
		setWindowTitle(titleIn);
		setWindowMessage(messageIn);
		buttonText = DEFAULT_BUTTON_TEXT;
		Label label = new Label(message);
		Button exitButton = new Button(buttonText);
		
		label.setTranslateY(-50);
		exitButton.setOnAction(e -> window.close());
		exitButton.setTranslateY(10);
		layout.getChildren().addAll(label, exitButton);
		layout.setAlignment(Pos.CENTER);
		window.initModality(Modality.APPLICATION_MODAL);
		window.setTitle(title);
		window.setScene(scene);
		
		window.showAndWait();
	}

	
	public static void displayAlertWindow(String messageIn)
	{
		Stage window = new Stage();
		StackPane layout = new StackPane();
		Scene scene = new Scene(layout, DEFAULT_XAXIS, DEFAULT_YAXIS);
		title = DEFAULT_WINDOW_TITLE;
		setWindowMessage(messageIn);
		buttonText = DEFAULT_BUTTON_TEXT;
		Label label = new Label(message);
		Button exitButton = new Button(DEFAULT_BUTTON_TEXT);
		
		label.setTranslateY(-30);
		exitButton.setOnAction(e -> window.close());
		layout.getChildren().addAll(label, exitButton);
		window.initModality(Modality.APPLICATION_MODAL);
		window.setTitle(title);
		window.setScene(scene);
		
		window.show();
	}
	
	
	public static void displayAlertWindow(String messageIn, double xAxisIn, double yAxisIn)
	{
		Stage window = new Stage();
		StackPane layout = new StackPane();
		Scene scene = new Scene(layout, xAxis = xAxisIn, yAxis = yAxisIn);
		title = DEFAULT_WINDOW_TITLE;
		setWindowMessage(messageIn);
		buttonText = DEFAULT_BUTTON_TEXT;
		Label label = new Label(message);
		Button exitButton = new Button(buttonText);
		
		label.setTranslateY(-30);
		exitButton.setOnAction(e -> window.close());
		layout.getChildren().addAll(label, exitButton);
		window.initModality(Modality.APPLICATION_MODAL);
		window.setScene(scene);
		
		window.show();
	}

	
	private static void setWindowTitle(String titleIn)
	{ title = titleIn != null ? titleIn : DEFAULT_WINDOW_TITLE; }
	
	public static String getWindowTitle()
	{ return title != null ? title : DEFAULT_WINDOW_TITLE; }
	
	
	private static void setWindowMessage(String msg)
	{ message = msg; } // Warning: parameter may be null
	
	private static String getWindowMessage()
	{ return message; }
	
	
	public static void setButtonText(String buttonTextIn)
	{ buttonText = buttonTextIn != null ? buttonTextIn : DEFAULT_BUTTON_TEXT; }
	
	public static String getButtonText()
	{ return buttonText != null ? buttonText : DEFAULT_BUTTON_TEXT; }
}


