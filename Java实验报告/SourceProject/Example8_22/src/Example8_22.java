import java.util.regex.*;
public class Example8_22 {
	public static void main(String args[]){
		String s="市话:76.8元,长途:167.38元,短信:12.68元";
		String regex="[0123456789.]+";
		Pattern p=Pattern.compile(regex);
		Matcher m=p.matcher(s);
		double sum=0;
		while(m.find()){
			String item=m.group();
			System.out.println(item);
			sum=sum+Double.parseDouble(item);
		}
		System.out.println("账单总价格:"+sum);
	}

}
