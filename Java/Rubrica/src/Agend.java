import java.util.ArrayList;
import java.util.Iterator;

public class Agend 
{
	private final int MAX_CONTACTS = 5;
	private ArrayList<Contact> contacts = new ArrayList<>();
	private int i = 1;
	
	public Agend()
	{}
	
	public Agend(Contact contact)
	{
		addContact(contact);
	}
	
	
	public void addContact(Contact contact)
	{
		if (i <= MAX_CONTACTS) {
			this.contacts.add(contact);
			++i;
		}
	}
	
	public void showContacts()
	{
		Iterator<Contact> i = contacts.iterator();
		for (Contact c : contacts) 
			if (i.hasNext()) {
				String tmp = c.getAddress() != null ? c.getName() + " \t" + c.getPhoneNumber() + " \t" + c.getAddress() + '\n'
													: c.getName() + " \t" + c.getPhoneNumber() + '\n';
				System.out.println(tmp);
			}
	}
	
}
