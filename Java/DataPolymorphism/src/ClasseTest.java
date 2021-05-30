public class ClasseTest
{
	public static void main(String[] args)
	{
		Punto punto0 = new Punto();
		
		punto0.setX(4);
		punto0.setY(6);
		System.out.println(punto0.getX());
		System.out.println(punto0.getY());
		System.out.println(punto0.distanzaDallOrigine());
		System.out.println();
		
		PuntoTridimensionale punto1 = new PuntoTridimensionale();
		
		punto1.setX(7);
		punto1.setY(3);
		punto1.setZ(9);
		System.out.println(punto1.getX());
		System.out.println(punto1.getY());
		System.out.println(punto1.getZ());
		System.out.println(punto1.distanzaDallOrigine());
		System.out.println();
		
		Punto punto2 = new PuntoTridimensionale();
		
		punto2.setX(10);
		punto2.setY(6);
		
		
		
		
	}
}
