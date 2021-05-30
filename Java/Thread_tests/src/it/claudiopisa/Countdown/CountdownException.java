package it.claudiopisa.Countdown;

public class CountdownException extends Exception 
{
	private static final long serialVersionUID = 1L;
	private static final String DEFAULT_MSG = "Error";
	private String _msg;
	

	public CountdownException(String _msg)
	{
		if (_msg.isEmpty())
			this._msg = DEFAULT_MSG;
		else
			this._msg = _msg;
	}
	
	public CountdownException(){}
	
	@Override
	public String toString()
	{
		return _msg;
	}
}
