/*p.146 Esercizio 4.b
Scrivere un'applicazione che stampi i 26 caratteri dell’alfabeto (inglese-americano) con un ciclo.*/

package printAlfabeto;

public class printAlfabeto 
{
	public static void main(String[] args) 
	{
		/* With two cycles
		System.out.println("Upper case\n-");
		for(int i = 65; i <= 90; i++){
			System.out.println((char) i);
			if(i == 90){
				System.out.println("-\nLower case\n-");
				for(int j = 97; j <= 122; j++){
					System.out.println((char) j);
				}
		}*/
		
		/* With on cycle */
		int i = 65, j = 90;
		System.out.println("Upper case\n-");
		while(i <= j){
			if(i == 90){
				i = 97; 
				j = 122;
				System.out.println("-\nLower case\n-");
			}
			System.out.println((char) i++);
		}

	}

}
