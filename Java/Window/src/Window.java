import java.awt.Frame;

import javax.swing.JFrame;

public class Window
{

	public static void main(String[] args) 
	{
		Frame window_0 = new Frame("Frame 1");
		window_0.setSize(1920, 720);
		window_0.setVisible(true);
		
		Frame window_1 = new Frame("Frame 2");
		window_1.setSize(500, 500);
		window_1.setVisible(true);
	}
}

