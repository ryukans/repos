public class Contact extends Person
{
	private String phoneNumber;
	private String address;

	public Contact(String name, String phoneNumber)
	{
		super(name);
		setPhoneNumber(phoneNumber);
	}
	
	public Contact(String name, String phoneNumber, String address)
	{
		this(name, phoneNumber);
		setAddress(address);
	}
	
	
	public void setPhoneNumber(String phoneNumber)
	{
		if (phoneNumber.isEmpty())
			System.out.println("Error -- phone number must be specified");
		else {
			String tmp = removeBlanks(phoneNumber);
			if (tmp.length() == 10)
				this.phoneNumber = phoneNumber.trim();
			else
				this.phoneNumber = "Phone number is not valid";
		}
	}
	
	public String getPhoneNumber()
	{
		return this.phoneNumber;
	}
	
	
	public void setAddress(String address)
	{
		this.address = address;
	}
	
	public String getAddress()
	{
		return this.address;
	}
	
	
	private String removeBlanks(String s)
	{
		String s2 = "";
		
		for (int i = 0; i < s.length(); ++i) {
			if (!(s.charAt(i) == ' '))
				s2 += s.charAt(i);
		}
		
		return s2;
	}
	
}
