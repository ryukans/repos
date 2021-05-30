/* p.146 Esercizio 4.a
Scrivere un semplice programma, costituito da un’unica classe, che sfruttando
esclusivamente un ciclo infinito, l’operatore modulo, due costrutti if, un break ed un
continue, stampi solo i primi cinque numeri pari. */

public class numeriPari 
{

	public static void main(String[] args) 
	{	
		int i = 0;
		while(true)
		{
			i++;
			if(i > 10)
				break;
			if(i % 2 != 0)
				continue;
			
			System.out.println("> " + i);
		}
		
	}

}
