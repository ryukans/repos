package interfaces;

public interface Warehouse
{
    void deposit(String item, int id);
    int withdraw(String item);
}
