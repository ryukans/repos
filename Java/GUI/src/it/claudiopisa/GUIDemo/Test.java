package it.claudiopisa.GUIDemo;

import java.awt.EventQueue;
import javax.swing.JFrame;
import java.awt.SystemColor;
import java.awt.Toolkit;
import javax.swing.JToolBar;
import java.awt.BorderLayout;
import javax.swing.JButton;
import java.awt.Font;
import javax.swing.SwingConstants;
import javax.swing.JPanel;
import javax.swing.border.TitledBorder;
import javax.swing.border.SoftBevelBorder;
import javax.swing.border.BevelBorder;
import javax.swing.UIManager;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JPasswordField;

public class Test
{
	private JFrame frame;
	private JPasswordField passwordField;

	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable(){
			public void run()
			{
				try
				{
					Test window = new Test();
					window.frame.setVisible(true);
				}
				catch (Exception exc)
				{ exc.printStackTrace(); }
			}
		});
	}

	
	/**
	 * Create the application.
	 */
	public Test() 
	{ initialize(); }

	
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize()
	{
		frame = new JFrame();
		frame.setBounds(100, 100, 648, 427);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JPanel panel0Button0 = new JPanel();
		panel0Button0.setBounds(151, 137, 101, 46);
		frame.getContentPane().add(panel0Button0);
		panel0Button0.setLayout(null);
		
		JButton button0 = new JButton("Test");
		button0.setBounds(6, 16, 89, 23);
		panel0Button0.add(button0);
		button0.setToolTipText("This is a test button");
		button0.setMnemonic('C');
		
		passwordField = new JPasswordField();
		passwordField.setBounds(161, 280, 211, 20);
		frame.getContentPane().add(passwordField);
	}
}
