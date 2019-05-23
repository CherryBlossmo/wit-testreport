import java.awt.*;
import java.awt.event.*;
import java.io.File;

import javax.swing.*;

public class MainFrame implements ActionListener {
	
	JFrame f = new JFrame("load zip");
	
	JLabel zipfilepath = new JLabel("[文件]:");
	JLabel outpath = new JLabel("[解压目录]:");
	
	String strfile = null;
	String strout = null;
	
	public MainFrame() {
		
		f.setSize(800, 600);
		f.setLocation(300,200);
		f.setLayout(new FlowLayout(FlowLayout.LEFT, 10, 20));
		
		f.add(zipfilepath);
		f.add(outpath);
		
		JButton btn = new JButton("选择解压文件");
		btn.addActionListener(this);
		f.add(btn);
		
		JButton btn2 = new JButton("选择解压目录");
		btn2.addActionListener(this);
		f.add(btn2);
		
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}

	public void actionPerformed(ActionEvent e) {
	     JButton button=(JButton)e.getSource();
	     String actionCommand = button.getActionCommand();
	     System.out.println(actionCommand);
	     if(actionCommand.equals("选择解压文件")){
			JFileChooser jfc = new JFileChooser();
			jfc.setFileSelectionMode(JFileChooser.FILES_ONLY);
			jfc.showDialog(new JLabel(), "选择");
			File file = jfc.getSelectedFile();
			if (file != null) {
				strfile = file.getAbsolutePath();
				zipfilepath.setText("文件:" + strfile);
			}
	     }else if(actionCommand.equals("选择解压目录")){
			JFileChooser jfc = new JFileChooser();
			jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
			jfc.showDialog(new JLabel(), "选择");
			File file = jfc.getSelectedFile();
			if (file != null) {
				strout = file.getAbsolutePath();
				System.out.println("解压目录:" + file.getAbsolutePath());
				outpath.setText("解压目录:" + file.getAbsolutePath());
				if (ZIP.unZip(new File(strfile), strout)) {
					JOptionPane.showMessageDialog(null, "解压完成", "OK", JOptionPane.INFORMATION_MESSAGE);
				}
			}
	     }
	}
}
