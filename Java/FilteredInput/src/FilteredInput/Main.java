package FilteredInput;

import java.io.DataInput;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        double d = 0;
        int i = 0;
        String s = "";

        try {
            FileInputStream fis = new FileInputStream("./text.txt");
            DataInputStream dis = new DataInputStream(fis);

            //reading
            d = dis.readDouble();
            i = dis.readInt();
            s = dis.readUTF();

            //close chain, must close in reverse order
            dis.close();
            fis.close();
        } catch (IOException e) {
            System.out.println("No such file or directory");
        }

        System.out.println("Double: " + d
                            + "\nInteger: " + i
                            + "\nString: " + s);

    }
}
