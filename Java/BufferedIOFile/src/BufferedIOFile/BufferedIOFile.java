package BufferedIOFile;

import java.io.*;

public class BufferedIOFile
{
    public static void write(File fileName) throws  IOException
    {
        BufferedWriter output = new BufferedWriter(new FileWriter(fileName));

        output.write("Hello World\n");
        output.write("The quick brown fox jumps over the lazy dog");

        output.close();
    }

    public static String read(File fileName) throws IOException
    {
        //FileReader fr = new FileReader(fileName);
        BufferedReader input = new BufferedReader(new FileReader(fileName));
        String s;
        StringBuilder sb = new StringBuilder();

        //read input by lines
        while((s = input.readLine()) != null)
            sb.append(s + '\n');

        input.close();

        return sb.toString();
    }

    public static void main(String[] args) throws IOException
    {
        File file = new File("./Test.txt");

        write(file);
        System.out.print(read(file));
    }
}
