package it.claudiopisa.ChoiceBox;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import it.claudiopisa.AlertWindow.AlertWindow;

@SuppressWarnings("unused")
public class Test extends Application
{
	
	private Stage window;
	private Scene scene;
	private BorderPane layout;
	private HBox bottomLayout;
	private VBox centerLayout;

	public static void main(String[] args) 
	{
		launch(args);
	}

	@Override
	public void start(Stage window) throws Exception
	{
		this.window = window;
		this.layout = new BorderPane();
		this.scene = new Scene(layout, 300, 250);
		this.bottomLayout = new HBox();
		this.centerLayout = new VBox();
		Button seeOptions = new Button("See option");
		Button exitButton = new Button("Ok");
		ChoiceBox<String> choiceBox = new ChoiceBox<String>();
		
		exitButton.setOnAction(e -> window.close());
		exitButton.setTranslateX(170);
		exitButton.setTranslateY(-10);
		seeOptions.setOnAction(e -> echoOptions(choiceBox));
		seeOptions.setTranslateX(150);
		seeOptions.setTranslateY(-10);
		//choiceBox.setValue("Op0");
		//choiceBox.getSelectionModel().select(0);
		//choiceBox.getSelectionModel().selectedItemProperty().addListener((v, oldValue, newValue) -> System.out.println(Color.ALICEBLUE));
		//choiceBox.setOnAction(e -> System.out.println(Color.getValue()));
		choiceBox.getItems().addAll("Red", "Blue", "Green", "Yellow");
		choiceBox.setTranslateX(110);
		bottomLayout.getChildren().addAll(seeOptions, exitButton);
		centerLayout.getChildren().add(choiceBox);
		layout.setPadding(new Insets(10, 0, 0, 10));
		layout.setCenter(centerLayout);
		layout.setBottom(bottomLayout);
		
		window.setTitle("ChoiceBox test");
		window.setScene(scene);
		window.show();
	}
	
	private void echoOptions(ChoiceBox<String> choiceBox)
	{
		AlertWindow.displayAlertWindow("Options", choiceBox.getValue() == null ? "No option selected" : "Selected option is " + choiceBox.getValue(), 150, 130);
	}
}



