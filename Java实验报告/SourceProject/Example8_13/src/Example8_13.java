
public class Example8_13 {
	public static void main(String args[]){
		String cost="�л�76.8Ԫ,��;��167.38Ԫ,����12.68Ԫ";
		double priceSum=GetPrice.givePriceSum(cost);
		System.out.printf("%s\n�ܼ�:%.2fԪ\n",cost,priceSum);
		cost="ţ��:8.5Ԫ,�㽶3.6Ԫ,����:2.8Ԫ";
		priceSum=GetPrice.givePriceSum(cost);
		System.out.printf("%s\n�ܼ�:%.2fԪ\n",cost,priceSum);		
	}

}
