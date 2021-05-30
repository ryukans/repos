import javax.swing.JFrame;
import javax.swing.JLabel;


public class Demo
{

	public static void main(String[] args)
	{
		JFrame frame_0 = new JFrame("GUI-Hello World !");
		JLabel text = new JLabel("Hello World !");
		
		frame_0.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // frame_0.EXIT_ON_CLOSE
		frame_0.setVisible(true);
		frame_0.add(text);
	}
}
