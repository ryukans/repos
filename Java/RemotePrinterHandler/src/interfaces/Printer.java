package interfaces;

import java.rmi.Remote;

public interface Printer extends Remote
{
    boolean print(String docName);
}
