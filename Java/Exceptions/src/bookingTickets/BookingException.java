package bookingTickets;

public class BookingException extends Exception
{
	private static final long serialVersionUID = 1L;

	public BookingException() {
		super("Error");
	}

	@Override
	public String toString() {
		return getMessage() + " -- no more tickets avaible";
	}
}
