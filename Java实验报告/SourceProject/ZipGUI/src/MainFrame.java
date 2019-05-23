import java.awt.*;
import java.awt.event.*;
import java.io.File;

import javax.swing.*;

public class MainFrame implements ActionListener {
	
	JFrame f = new JFrame("load zip");
	
	JLabel zipfilepath = new JLabel("[�ļ�]:");
	JLabel outpath = new JLabel("[��ѹĿ¼]:");
	
	String strfile = null;
	String strout = null;
	
	public MainFrame() {
		
		f.setSize(800, 600);
		f.setLocation(300,200);
		f.setLayout(new FlowLayout(FlowLayout.LEFT, 10, 20));
		
		f.add(zipfilepath);
		f.add(outpath);
		
		JButton btn = new JButton("ѡ���ѹ�ļ�");
		btn.addActionListener(this);
		f.add(btn);
		
		JButton btn2 = new JButton("ѡ���ѹĿ¼");
		btn2.addActionListener(this);
		f.add(btn2);
		
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
	     JButton button=(JButton)e.getSource();
	     String actionCommand = button.getActionCommand();
	     System.out.println(actionCommand);
	     if(actionCommand.equals("ѡ���ѹ�ļ�")){
			JFileChooser jfc = new JFileChooser();
			jfc.setFileSelectionMode(JFileChooser.FILES_ONLY);
			jfc.showDialog(new JLabel(), "ѡ��");
			File file = jfc.getSelectedFile();
			if (file != null) {
				strfile = file.getAbsolutePath();
				zipfilepath.setText("�ļ�:" + strfile);
			}
	     }else if(actionCommand.equals("ѡ���ѹĿ¼")){
			JFileChooser jfc = new JFileChooser();
			jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			jfc.showDialog(new JLabel(), "ѡ��");
			File file = jfc.getSelectedFile();
			if (file != null) {
				strout = file.getAbsolutePath();
				System.out.println("��ѹĿ¼:" + file.getAbsolutePath());
				outpath.setText("��ѹĿ¼:" + file.getAbsolutePath());
				if (ZIP.unZip(new File(strfile), strout)) {
					JOptionPane.showMessageDialog(null, "��ѹ���", "OK", JOptionPane.INFORMATION_MESSAGE);
				}
			}
	     }
	}
}
