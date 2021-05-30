package application;

import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class InterfaceController 
{
	public Button showLabel = new Button();
	public Label label = new Label();
	
	public void showLabel()
	{
		showLabel.setOnAction(e -> {
			label.setText("Yay");
			showLabel.setText("You touched me :3");
		});
	}
	
	
}
