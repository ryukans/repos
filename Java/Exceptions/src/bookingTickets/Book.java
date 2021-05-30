package bookingTickets;

public class Book
{
	private static int tickets = 3;
	private String ticketLabel;

	/* default constructor */
	
	public void book() throws BookingException
	{
		if (tickets == 0) throw new BookingException();
		
		setTicketLabel();
		--tickets;
	}
	
	
	private void setTicketLabel() {
		this.ticketLabel = "Ticket <" + tickets + '>';
	}
	
	public String getTicketLabel() {
		return this.ticketLabel;
	}
	
	
	public static int seeAvaibleTickets() {
		return tickets;
	}
}


