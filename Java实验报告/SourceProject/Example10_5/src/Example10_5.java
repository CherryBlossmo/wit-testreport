import java.io.*;
public class Example10_5 {
	public static void main(String args[]){
		byte[] a="�������".getBytes();
		byte[] b="Happy New Year".getBytes();
		File file=new File("a.txt");
		try{
			OutputStream out=new FileOutputStream(file);
			System.out.println(file.getName()+"�Ĵ�С:"+file.length()+"�ֽ�");
			out.write(a);
			out.close();
			out=new FileOutputStream(file,true);
			System.out.println(file.getName()+"�Ĵ�С:"+file.length()+"�ֽ�");
			out.write(b,0,b.length);
			System.out.println(file.getName()+"�Ĵ�С:"+file.length()+"�ֽ�");
			
			out.close();
		}
		catch(IOException e){
			System.out.println("Error "+e);
		}
	}

}
