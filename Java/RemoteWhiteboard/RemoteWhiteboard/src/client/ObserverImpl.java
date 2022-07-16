package client;

import java.io.Serial;
import java.rmi.RemoteException;
import java.rmi.server.*;
import java.util.*;

import whiteboard.*;
import whiteboard.Observer;

public class ObserverImpl extends UnicastRemoteObject implements Observer {

	@Serial
	private static final long serialVersionUID = 1L;
	
	private Whiteboard remoteWhiteboard;	//riferimento alla lavagna remota
	
	public ObserverImpl ( Whiteboard w) throws RemoteException {
		remoteWhiteboard = w;
	}
	
	
	/*
	 * Implementazione del callbackMethod: il lato server notifica al client
	 * che e' stata aggiunta una nuova forma geometrica sulla lavagna;
	 * il client richiede lo stato corrente della lavagna
	 */
	
	
	public void observerNotify () throws RemoteException{

		System.out.println ("\n\nNotified! Current board content: ");
		
		//invocazione remota sul subject ( Whiteboard )
		Vector<Shape> v = remoteWhiteboard.getShapes();
		
		int size = v.size();

		for ( int i =0; i<size; i++)
			((Shape)v.get(i)).draw();
		
	}
	
}
