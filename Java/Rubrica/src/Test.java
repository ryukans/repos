public class Test 
{
	public static void main(String[] args)
	{
		Agend agend = new Agend(new Contact("Giovanni", "366 377 0808", "Via dell"));
		
		agend.addContact(new Contact("Claudio Pisa", "3663770808", "Via dell'Epomeo"));
		agend.addContact(new Contact("Keanu Reevs", "366 377 0808"));
		agend.addContact(new Contact("No name", "366377 0909", "Via della Via"));
		agend.addContact(new Contact("Znnnrrn", "366 377 08089", "Via in delle"));
		agend.addContact(new Contact("Tuunnnannaaaa", "366 3770808"));
		
		agend.showContacts();
		
		System.out.println();
		
		Agend agend1 = new Agend();
		Contact contact = new Contact("Spider Man", "366 377 0808", "Somewhere in New York");
		
		agend1.addContact(contact);
		
		agend1.showContacts();
	}

}
