package it.claudiopisa.CheckBox;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import it.claudiopisa.AlertWindow.AlertWindow;

public class Test extends Application
{
	private final int MAX_BOXES = 5;
	@SuppressWarnings("unused")
	private Stage window;
	private Scene scene;
	private VBox layout;
	
	public static void main(String[] args) 
	{
		launch(args);
	}

	@Override
	public void start(Stage window) throws Exception 
	{
		this.window = window;
		this.layout = new VBox();
		this.scene = new Scene(layout, 230, 195);
		Button exitButton = new Button("Cancel");
		Button seeBoxes = new Button("See selected");
		CheckBox[] checkBoxes = new CheckBox[MAX_BOXES];
		
		setCheckBoxes(checkBoxes);
		layout.getChildren().addAll(checkBoxes);
		layout.getChildren().addAll(exitButton, seeBoxes);
		layout.setPadding(new Insets(10, 0, 0, 10));
		exitButton.setTranslateX(150);
		exitButton.setTranslateY(50);
		exitButton.setOnAction(e -> window.close());
		seeBoxes.setTranslateX(50);
		seeBoxes.setTranslateY(25);
		seeBoxes.setOnAction(e -> echoSelectedBoxes(checkBoxes));
		checkBoxes[0].setOnAction(e -> {
			Label label = new Label("Option 1 activated");
			label.setTranslateX(100);
			label.setTranslateY(-95);
			layout.getChildren().add(label);
		});
		checkBoxes[1].setSelected(true);
		setCheckBoxXAxis(checkBoxes, 25);
		setCheckBoxYAxis(checkBoxes, 15);
		
		window.setTitle("CheckBox test");
		window.setScene(scene);
		window.show();
	}
	
	
	private void setCheckBoxes(CheckBox[] cb)
	{
		for	(int i = 0; i < MAX_BOXES; i++)
			cb[i] = new CheckBox(String.format("Option %d", i+1));
	}
	
	private void setCheckBoxXAxis(CheckBox[] cb, double xAxis)
	{
		for (int i = 0; i < MAX_BOXES; i++)
			cb[i].setTranslateX(xAxis);
	}
	
	private void setCheckBoxYAxis(CheckBox[] cb, double yAxis)
	{
		for (int i = 0; i < MAX_BOXES; i++)
			cb[i].setTranslateY(yAxis);
	}
	
	private void echoSelectedBoxes(CheckBox[] cb)
	{
		String selectedBoxes = "";
		
		for (int i = 0; i < MAX_BOXES; i++)
			if (cb[i].isSelected())
				selectedBoxes += String.format("-Box %d is selected\n", i+1);
		
		if (selectedBoxes.equals(""))
			AlertWindow.displayAlertWindow("Selected boxes", "No boxes were selected");
		else
			AlertWindow.displayAlertWindow("Selected boxes", selectedBoxes);
	}
	
}


