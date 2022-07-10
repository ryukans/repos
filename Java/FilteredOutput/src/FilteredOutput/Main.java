package FilteredOutput;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Main
{
    public static void main(String[] args)
    {
        try {
            FileOutputStream fos = new FileOutputStream("./text.txt");
            BufferedOutputStream bos = new BufferedOutputStream(fos);
            DataOutputStream dos = new DataOutputStream(bos);

            //writing
            dos.writeDouble(140.15);
            dos.writeInt(14015);
            dos.writeUTF("Meryl");
            dos.flush();

            //close chain
            dos.close();
            fos.close();
        } catch (IOException e) {}
    }
}
