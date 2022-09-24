package interfaces;

import java.io.Serializable;

public interface Readable extends Serializable
{
    String getType();
    void setType(String type);
    int getValue();
    void setValue(int value);
}
