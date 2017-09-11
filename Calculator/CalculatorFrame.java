package calculator;
import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JLabel;

public class CalculatorFrame extends JFrame implements ActionListener {

	private JPanel contentPane, panel_1, panel;
	private JTextField Num1;
	private JTextField Num2;
	private JButton add, sub, mul, div, clear;
	private JTextArea Result;
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CalculatorFrame frame = new CalculatorFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public CalculatorFrame() {
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		panel = new JPanel();
		panel.setBounds(5, 5, 422, 156);
		contentPane.add(panel);
		panel.setLayout(null);
		
		Num1 = new JTextField();
		Num1.setBounds(25, 38, 129, 33);
		panel.add(Num1);
		Num1.setColumns(10);
		Num1.addActionListener(this);
		
		Num2 = new JTextField();
		Num2.setBounds(270, 38, 129, 33);
		panel.add(Num2);
		Num2.setColumns(10);
		Num2.addActionListener(this);
		
		JLabel lblNum = new JLabel("Num 1");
		lblNum.setBounds(61, 13, 56, 16);
		panel.add(lblNum);
		
		JLabel lblNum_1 = new JLabel("Num 2");
		lblNum_1.setBounds(306, 13, 56, 16);
		panel.add(lblNum_1);
		
		JLabel lblResult = new JLabel("Result");
		lblResult.setBounds(188, 72, 56, 16);
		panel.add(lblResult);
		
		Result = new JTextArea();
		Result.setBounds(146, 101, 129, 42);
		panel.add(Result);
		
		panel_1 = new JPanel();
		panel_1.setBounds(5, 174, 422, 66);
		contentPane.add(panel_1);
		panel_1.setLayout(null);
		
		add = new JButton("+");
		add.setFont(new Font("Times New Roman", Font.BOLD, 22));
		add.addActionListener(this);
		add.setBounds(27, 13, 47, 40);
		panel_1.add(add);
		
		sub = new JButton("-");
		sub.addActionListener(this);
		sub.setFont(new Font("Times New Roman", Font.BOLD, 27));
		sub.setBounds(103, 13, 47, 40);
		panel_1.add(sub);
		
		mul = new JButton("*");
		mul.addActionListener(this);
		mul.setFont(new Font("Times New Roman", Font.BOLD, 22));
		mul.setBounds(188, 13, 47, 40);
		panel_1.add(mul);
		
		div = new JButton("/");
		div.addActionListener(this);
		div.setFont(new Font("Times New Roman", Font.BOLD, 27));
		div.setBounds(273, 13, 47, 40);
		panel_1.add(div);
		
		clear = new JButton("C");
		clear.addActionListener(this);
		clear.setFont(new Font("Times New Roman", Font.BOLD, 18));
		clear.setBounds(363, 13, 47, 40);
		panel_1.add(clear);
		
	}

	
	public void actionPerformed(ActionEvent e) {
		double n1= Double.parseDouble(Num1.getText());
		double n2= Double.parseDouble(Num2.getText());
	
		if (e.getSource() == add)
		{
			Result.setText(String.valueOf(n1+n2));
		}
		else if (e.getSource() == sub)
		{
			Result.setText(String.valueOf(n1-n2));
		}
		else if (e.getSource() == mul)
		{
			Result.setText(String.valueOf(n1*n2));
		}
		if (e.getSource() == div)
		{
			Result.setText(String.valueOf(n1/n2));
		}
		else if (e.getSource() == clear)
		{
			Num1.setText(" ");
			Num2.setText(" ");
			Result.setText("");
		}
	}
}
