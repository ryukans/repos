package it.Geometry.graphic;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import java.awt.Color;
import javax.swing.JTextArea;
import javax.swing.border.SoftBevelBorder;
import javax.swing.border.BevelBorder;
import javax.swing.border.TitledBorder;
import javax.swing.UIManager;
import javax.swing.border.CompoundBorder;
import javax.swing.border.MatteBorder;
import javax.swing.JProgressBar;
import javax.swing.JLabel;
import javax.swing.LayoutStyle.ComponentPlacement;
import java.awt.SystemColor;
import java.awt.Font;
import javax.swing.JSeparator;
import javax.swing.JTree;
import javax.swing.event.AncestorListener;
import javax.swing.event.AncestorEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class InfosWindow extends JFrame
{
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	
	public static void main(String[] args){
		EventQueue.invokeLater(new Runnable(){
			public void run(){
				try{
					InfosWindow frame = new InfosWindow();
					frame.setVisible(true);
				} 
				catch (Exception exc){ exc.printStackTrace(); }
			}
		});
	}

	
	public InfosWindow()
	{
		setBackground(Color.WHITE);
		setTitle("Infos Window");
		setOpacity(50.0f);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setForeground(SystemColor.control);
		contentPane.setBackground(Color.DARK_GRAY);
		contentPane.setBorder(new SoftBevelBorder(BevelBorder.LOWERED, null, null, null, null));
		setContentPane(contentPane);
		
		JLabel lblName = new JLabel("Name:");
		lblName.setFont(new Font("Segoe UI Symbol", Font.PLAIN, 14));
		lblName.setForeground(SystemColor.controlHighlight);
		
		JLabel lblNumberOfSides = new JLabel("Number of sides:");
		lblNumberOfSides.setFont(new Font("Segoe UI Symbol", Font.PLAIN, 14));
		lblNumberOfSides.setForeground(SystemColor.controlHighlight);
		
		JLabel lblNumberOfAngles = new JLabel("Number of angles:");
		lblNumberOfAngles.setForeground(SystemColor.controlHighlight);
		lblNumberOfAngles.setFont(new Font("Segoe UI Symbol", Font.PLAIN, 14));
		
		JLabel lblPerimeter = new JLabel("Perimeter:");
		lblPerimeter.setForeground(SystemColor.controlHighlight);
		lblPerimeter.setFont(new Font("Segoe UI Symbol", Font.PLAIN, 14));
		
		JLabel lblArea = new JLabel("Area:");
		lblArea.setForeground(SystemColor.controlHighlight);
		lblArea.setFont(new Font("Segoe UI Symbol", Font.PLAIN, 14));
		
		JLabel lblInputName = new JLabel("New label");
		
		
		JLabel labelSides = new JLabel("New label");
		
		JLabel labelAngles = new JLabel("New label");
		
		JLabel labelPerimeter = new JLabel("New label");
		
		JLabel labelArea = new JLabel("New label");
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addComponent(lblName)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(lblInputName))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addComponent(lblNumberOfSides)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(labelSides))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addComponent(lblArea, GroupLayout.PREFERRED_SIZE, 103, GroupLayout.PREFERRED_SIZE)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(labelArea))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addComponent(lblNumberOfAngles)
							.addGap(61)
							.addComponent(labelAngles))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addComponent(lblPerimeter, GroupLayout.PREFERRED_SIZE, 103, GroupLayout.PREFERRED_SIZE)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(labelPerimeter)))
					.addContainerGap(199, Short.MAX_VALUE))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblName)
						.addComponent(lblInputName))
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNumberOfSides)
						.addComponent(labelSides))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNumberOfAngles, GroupLayout.PREFERRED_SIZE, 20, GroupLayout.PREFERRED_SIZE)
						.addComponent(labelAngles))
					.addGap(12)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblPerimeter, GroupLayout.PREFERRED_SIZE, 20, GroupLayout.PREFERRED_SIZE)
						.addComponent(labelPerimeter))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblArea, GroupLayout.PREFERRED_SIZE, 20, GroupLayout.PREFERRED_SIZE)
						.addComponent(labelArea))
					.addContainerGap(110, Short.MAX_VALUE))
		);
		contentPane.setLayout(gl_contentPane);
	}
}

