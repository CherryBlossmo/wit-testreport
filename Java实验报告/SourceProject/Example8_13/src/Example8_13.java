
public class Example8_13 {
	public static void main(String args[]){
		String cost="市话76.8元,长途：167.38元,短信12.68元";
		double priceSum=GetPrice.givePriceSum(cost);
		System.out.printf("%s\n总价:%.2f元\n",cost,priceSum);
		cost="牛奶:8.5元,香蕉3.6元,酱油:2.8元";
		priceSum=GetPrice.givePriceSum(cost);
		System.out.printf("%s\n总价:%.2f元\n",cost,priceSum);		
	}

}
