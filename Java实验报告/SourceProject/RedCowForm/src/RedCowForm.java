
public class RedCowForm{ 
	static String formName;
	
    RedCow cow;
	
    RedCowForm(){}
	
    RedCowForm(String s){
    	cow=new RedCow(150,112,5000);
    	formName=s;
    }
	
    public void showCowMess(){
    	cow.speak();
    }
	
	class RedCow{
		String cowName="��ţ";
		
		int height,weight,price;
		
		RedCow(int h,int w,int p){
			height=h;
			weight=w;
			price=p;
		}
		
		void speak(){
			System.out.println("ż��"+cowName+",��ߣ�"+height+"cm ���أ�"+weight+"kg,������"+formName);
		}
	}
}


