package it.claudiopisa.BorderPane;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import it.claudiopisa.ConfirmBox.ConfirmBox;

public class Test extends Application
{
	private Stage window;
	private BorderPane layout;
	private HBox topMenu, bottomMenu;
	private VBox leftMenu, rightMenu;
	private Scene scene;

	public static void main(String[] args) 
	{
		launch(args);
	}

	
	@Override
	public void start(Stage window) throws Exception 
	{
		this.window = window;
		this.topMenu = new HBox();
		this.bottomMenu = new HBox();
		this.leftMenu = new VBox();
		this.rightMenu = new VBox();
		this.layout = new BorderPane();
		this.scene = new Scene(layout, 350, 350);
		
		Button button = new Button("Ok");
		Button exitButton = new Button("Ok");
		Button topButton0 = new Button("Click");
		Button topButton1 = new Button("Click");
		Button topButton2 = new Button("Click");
		Button bottomButton0 = new Button("Click");
		Button bottomButton1 = new Button("Click");
		Button bottomButton2 = new Button("Click");
		Button leftButton0 = new Button("Click");
		Button leftButton1 = new Button("Click");
		Button rightButton0 = new Button("Click");
		Button rightButton1 = new Button("Click");
		Label label = new Label("Border Pane test");
	
		window.setTitle("Border Pane test");
		window.setOnCloseRequest(e -> {
			e.consume();
			closeProgram();
		});
		
		topButton2.setTranslateX(175);
		topButton1.setTranslateX(150);
		topButton0.setTranslateX(100);
		topMenu.getChildren().addAll(topButton0, topButton1, topButton2);
		bottomMenu.getChildren().addAll(bottomButton0, bottomButton1, bottomButton2);
		leftMenu.getChildren().addAll(leftButton0, leftButton1);
		rightMenu.getChildren().addAll(rightButton0, rightButton1);
		layout.setTop(topMenu);
		layout.setBottom(bottomMenu);
		layout.setLeft(leftMenu);
		layout.setRight(rightMenu);
		layout.setCenter(label);
		
		
		window.setScene(scene);
		window.show();
	}
	
	private void closeProgram()
	{
		Boolean answer = ConfirmBox.displayConfirmBox("Exit", "Are you sure you want to exit ?");
		if (answer)
			window.close();
	}
}







