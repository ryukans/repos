package ByteArrayIO;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws  IOException{
        String message = "Test message";
        ByteArrayOutputStream os = new ByteArrayOutputStream();

        os.write(message.getBytes());
        System.out.println("Output stream: " + os);
        System.out.println("Size: " + os.size());

        ByteArrayInputStream is = new ByteArrayInputStream(os.toByteArray());
        int length = is.available(); //number of remaining bytes that can be read from this input stream.
        byte[] inputBuffer = new byte[length];
        int bytesRead = is.read(inputBuffer, 0, length);

        System.out.println("Byte(s) read: " + bytesRead);
        System.out.println("String: " + new String(inputBuffer));

    }
}
