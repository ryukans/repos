package interfaces.printer;

import java.rmi.Remote;

public interface IPrinter
{
    boolean print(String docName);
}
