import java.util.*;
public class PriceToken {
	public double getPriceSum(String shoppingReceipt){
		String regex="[^0123456789.]+";
		shoppingReceipt=shoppingReceipt.replaceAll(regex,"#");
		StringTokenizer fenxi=new StringTokenizer(shoppingReceipt,"#");
		double sum=0;
		while(fenxi.hasMoreTokens()){
			String item=fenxi.nextToken();
			double price=Double.parseDouble(item);
			sum=sum+price;
			
		}
		return sum;
	}
	
	public double getAverPrice(String shoppingReceipt) {
		double priceSum = getPriceSum(shoppingReceipt);
		int goodsAmount=getGoodsAmount(shoppingReceipt);
		return priceSum/goodsAmount;
	}
	
	
	public int getGoodsAmount(String shoppingReceipt){
		String regex="[^0123456789.]+";
		shoppingReceipt=shoppingReceipt.replaceAll(regex,"#");
		StringTokenizer fenxi=new StringTokenizer(shoppingReceipt,"#");
		int amount=fenxi.countTokens();
		return amount;
	}

}
