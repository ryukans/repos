package interfaces;

public interface Warehouse
{
    enum Operation  {
        DEPOSIT,
        WITHDRAW
    };


    void deposit(String item, int id);
    int withdraw(String item);
}
