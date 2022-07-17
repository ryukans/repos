package printer;

public interface Printer
{
    String ACKNOWNLEDGE_MESSAGE = "ACK";
    int BUFFER_SIZE = 100;
    String MESSAGE_TOKEN = "+";

    /*
    * Soluzione utile nel caso vi siano piu metodi invocabili tramite socket
    * */
    enum methods
    {
        print("print");
        final String method;
        methods(String method) {
            this.method = method;
        }

        @Override
        public String toString() {
            return method;
        }
    };
    boolean print(String docName);
}
