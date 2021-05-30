import com.sun.istack.internal.NotNull;

public class Greeter
{

    public static void main (String... args)
    {
        Greeter greeter = new Greeter();
        HelloWorldGreeting hwg = new HelloWorldGreeting();
        greeter.greet(hwg);

    }

    private void greet(@NotNull Greeting behavior) {
        behavior.perform();
    }
/*
    private void greet(@NotNull GreetingInterface behavior) {
        behavior.perform();
    }*/
}

