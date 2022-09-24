package dispatcher;

import interfaces.Readable;

import java.io.Serial;

public class Reading implements Readable
{
    private String type;
    private int value;

    @Serial
    private static final long serialVersionUID = -6459050799976113037L;

    public Reading()
    {
        type = "";
        value = 0;
    }

    public Reading(String type, int value)
    {
        this.type = type;
        this.value = value;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}
