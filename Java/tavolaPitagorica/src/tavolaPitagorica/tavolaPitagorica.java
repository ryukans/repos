package tavolaPitagorica;

public class tavolaPitagorica 
{
	public static void main(String[] args) 
	{
		int i = 1, j = 1;
		while(i <= 10 && j <= 10){
			System.out.printf("%d\t",  i*j);
			++j;
			if(j > 10){
				++i;
				j = 1;
				System.out.println();
			}
		}
	}
}

/*
	public static void main(String args[]) {
		for (int i = 1; i <= 10; ++i){
			for (int j = 1; j <= 10; ++j){
				System.out.print(i*j + "\t");
			}
		}
	}

*/
