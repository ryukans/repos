package it.claudiopisa.MW3WeaponGenerator;
	
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.control.RadioButton;
import java.util.Random;


public class Main extends Application
{
	private final int LIST_LENGTH = 18;
	private final int MAX_TYPES = 9; /* total rows */
	private final int MAX_WEAPONS = 10; /* total column */
	private final String[][] WEAPONS_SET = {
			{"M4A1", "M16A4", "SCAR-L", "CM901", "TYPE 95", "G36C", "ACR 6.8", "MK14", "AK-47", "FAD"},
			{"MP5","UMP45", "PP90M1", "P90", "PM-9", "MP7"},
			{"L86 LSW", "MG36", "PKP PECHENEG", "MK46", "M60E4"},
			{"BARRET CAL.50", "L118A", "DRAGUNOV", "AS50", "RSASS", "MSR"},
			{"USAS12", "KSG 12", "SPAS-12", "AA-12", "STRIKER", "MODEL 1887"},
			{"FMG9", "MP9", "SKORPION", "G18"},
			{"USP .45 TATTICA", "P99", "MP412", ".44 MAGNUM", "FIVE SEVEN", "DESERT EAGLE"},
			{"SMAW", "JAVELIN", "XM25", "M320 GLM", "RPG-7"},
			{"SCUDO ANTISOMMOSSA"}
	};
	static Random rand = new Random();
	private boolean repeat = false;

	public static void main(String[] args)
	{
		launch(args);
	}
	
	@Override
	public void start(Stage primaryWindow)
	{
		try {
			StackPane root = new StackPane();
			Scene scene = new Scene(root, 300, 400);
			Button generateButton = new Button("Genrate");
			RadioButton repeatWeapon = new RadioButton("Repeat weapons ?");
			Button exitButton = new Button("Exit");
			Label weaponsList = new Label("Click on Generate to create the list");
			
			generateButton.setOnAction(e -> weaponsList.setText(generateWeapons(repeat)));
			repeatWeapon.setOnAction(e -> repeat = (repeat == true) ? false : true);
			exitButton.setOnAction(e -> primaryWindow.close());
			StackPane.setAlignment(generateButton, Pos.BOTTOM_RIGHT);
			StackPane.setAlignment(repeatWeapon, Pos.BOTTOM_RIGHT);
			StackPane.setAlignment(exitButton, Pos.BOTTOM_RIGHT);
			StackPane.setAlignment(weaponsList, Pos.CENTER);
			generateButton.setTranslateX(-5);
			generateButton.setTranslateY(-15);
			repeatWeapon.setTranslateX(-170);
			repeatWeapon.setTranslateY(-15);
			exitButton.setTranslateX(-75);
			exitButton.setTranslateY(-15);
			weaponsList.setTranslateY(-15);
			root.getChildren().addAll(generateButton, repeatWeapon, exitButton, weaponsList);
			primaryWindow.setTitle("MW3 Weapon Generator");
			primaryWindow.setScene(scene);
			primaryWindow.show();
		} 
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private String generateWeapons(boolean repeat)
	{
		String weaponsList = "";
		int row = 0, column = 0;
		
		if (repeat) {
			for(int i = 0; i < LIST_LENGTH; i++) {
				row = rand.nextInt(MAX_TYPES);
				column = rand.nextInt(this.WEAPONS_SET[row].length);
				weaponsList += i+1 + "\t--\t" + this.WEAPONS_SET[row][column] + '\n';
			}
		}
		else {
			int i = 0;
			boolean[][] choosedWeapons = new boolean[MAX_TYPES][MAX_WEAPONS];
			
			while (i < LIST_LENGTH) {
				row = rand.nextInt(MAX_TYPES);
				column = rand.nextInt(this.WEAPONS_SET[row].length);
				if (!choosedWeapons[row][column]) {
					weaponsList += i+1 + "\t--\t" + this.WEAPONS_SET[row][column] + '\n';
					choosedWeapons[row][column] = true;
					++i;
				}
			}
		}
		
		return weaponsList;
	}
	
	/*
	private void setWeapons(int row, int column) 
	{
		row = rand.nextInt(MAX_TYPES);
		column = rand.nextInt(this.WEAPONS_SET[row].length);
	}*/

}



