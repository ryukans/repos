package package2;

import package1.Superclasse;

public class Sottoclasse extends Superclasse 
{
	@Override
	protected void metodo()
	{
		System.out.println("sottoclasse");
	}
	
	public void chiamaMetodoValido1()
	{
		super.metodo();
	}
	
	public void chiamaMetodoValido2(Sottoclasse oggetto)
	{
		oggetto.metodo();
	}
	
	public void chiamaMetodoNonValido(Superclasse oggetto)
	{
	//	oggetto.metodo();
	} 
}
