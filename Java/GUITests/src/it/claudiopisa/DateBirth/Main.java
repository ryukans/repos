package it.claudiopisa.DateBirth;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Main extends Application {
	
	private long STREAM = 0xCEEFBBL;
	private int MIN_DAYS = 28;
	private final int TOTAL_DAYS = 31;
	private final int TOTAL_MONTHS = 12;
	private final int FIRST_YEAR = 1950, LAST_YEAR = 2050;
	private final  String[] MONTHS = {
			"Gennuary", 
			"Febbruary", 
			"March", 
			"April", 
			"May", 
			"June", 
			"July", 
			"August", 
			"September", 
			"October", 
			"November", 
			"Dicember"
		};
	
	public static void main(String[] args) { 
		launch(args);
	}

	@Override
	public void start(Stage primaryWindow) throws Exception {
		
		StackPane root = new StackPane();
		Scene scene = new Scene(root, 400, 300);
		Label message = new Label("Your date birth");
		Label dateBirth = new Label();
		Label digitDateBirth = new Label();
		Button exitButton = new Button("Cancel");
		Button showDate = new Button("Show date");
		ComboBox<Integer> day = new ComboBox<Integer>();
		ComboBox<String> month = new ComboBox<String>();
		ComboBox<Integer> year = new ComboBox<Integer>();
		
		setComboBoxes(day, month, year);
		root.getChildren().addAll(message, dateBirth, digitDateBirth, exitButton, showDate, day, month, year);
		StackPane.setAlignment(message, Pos.TOP_CENTER);
		StackPane.setAlignment(dateBirth, Pos.TOP_LEFT);
		StackPane.setAlignment(digitDateBirth, Pos.TOP_RIGHT);
		StackPane.setAlignment(exitButton, Pos.BOTTOM_RIGHT);
		StackPane.setAlignment(showDate, Pos.BOTTOM_RIGHT);
		StackPane.setAlignment(day, Pos.CENTER_LEFT);
		StackPane.setAlignment(month, Pos.CENTER);
		StackPane.setAlignment(year, Pos.CENTER_RIGHT);
		message.setTranslateY(105);
		dateBirth.setTranslateX(65);
		dateBirth.setTranslateY(115);
		digitDateBirth.setTranslateX(-50);
		digitDateBirth.setTranslateY(115);
		exitButton.setTranslateX(-93);
		exitButton.setTranslateY(-35);
		showDate.setTranslateX(-10);
		showDate.setTranslateY(-35);
		day.setTranslateX(65);
		month.setTranslateX(3.5);
		year.setTranslateX(-50);
		day.setPromptText("Day");
		month.setPromptText("Month");
		year.setPromptText("Year");
		exitButton.setOnAction(e -> primaryWindow.close());
		showDate.setOnAction(e -> {
			echoDateBirth(dateBirth, day, month, year);
			echoDigitDateBirth(digitDateBirth, day, month, year);
		});
		month.setOnAction(e -> setDays(day, month, year));
		year.setOnAction(e -> setDays(day, month, year));
		
		
		primaryWindow.setTitle("Date bitrth");
		primaryWindow.setScene(scene);
		primaryWindow.show();
	}
	
	private void setComboBoxes(ComboBox<Integer> day, ComboBox<String> month, ComboBox<Integer> year) {
		setDays(day);
		setMonths(month);
		setYears(year);
	}
	
	private void setDays(ComboBox<Integer> day) {
		for (Integer days = 1; days <= TOTAL_DAYS; days++)
			day.getItems().add(days);
	}
	
	private void setDays(ComboBox<Integer> day, ComboBox<String> month, ComboBox<Integer> year) {

		//int minDays = 0;
	//	long stream = isLeapYear(year.getValue()) ? 0x89A66,  : 0xCEEFBB;
		

		/*if (isLeapYear(y)) {
			MIN_DAYS = 29;
			STREAM = 0x89A66L;
		}*/
		
		if (month.getValue() == null) return;
		
		if (year.getValue() != null) {
			Integer y = year.getValue();
			
			if ((y & 3) == 0 && ((y % 25) != 0 || (y & 15) == 0)) {
				MIN_DAYS = 29;
				STREAM = 0x899A66L;
			}
		}
		
		int x = getMonthNumber(month.getValue());
		
		int totalDays = (int) (MIN_DAYS+((STREAM >> ((TOTAL_MONTHS-x))*2)) & 0b11);
		
		//int tmpDays = 29 + (/*0xEEFBB3 0x99A662 >> (x-1)*2 & 0b11);		
		
		day.getItems().clear();
		for(Integer days = 1; days <= totalDays; days++)
			day.getItems().add(days); 
	}
	
	private void setMonths(ComboBox<String> month) {
		for (int months = 0; months < TOTAL_MONTHS; months++)
			month.getItems().add(this.MONTHS[months]);
	}
	
	private void setYears(ComboBox<Integer> year) {
		for (Integer years = FIRST_YEAR; years <= LAST_YEAR; years++)
			year.getItems().add(years);
	}
	
	
	private void echoDateBirth(Label dateBirth, ComboBox<Integer> day, ComboBox<String> month, ComboBox<Integer> year) {
		dateBirth.setText(
				
				day.getValue() != null && month.getValue() != null && year.getValue() != null ? 
						"On " + day.getValue() + " " + month.getValue() + ", " + year.getValue() 
						:
						"A field is missed !"
			);
	}
	
	private void echoDigitDateBirth(Label dateBirth, ComboBox<Integer> day, ComboBox<String> month, ComboBox<Integer> year) {
		dateBirth.setText(
				
				day.getValue() != null && month.getValue() != null && year.getValue() != null ?
						day.getValue() + "/" + getMonthNumber(month.getValue()) + "/" + year.getValue()
						: 
						"A field is missed !"
				);
	}
	
	private int getMonthNumber(String m) {
		int n = 0; /* stores month index */
		while (n < TOTAL_MONTHS && !(m == this.MONTHS[n++]));
	
		return n;
	}
	
	private boolean isLeapYear(int year) {
		//return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
		
		return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
	}
}







