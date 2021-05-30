public class HelloWorldGreeting
        extends Greeting implements GreetingInterface
{
    @Override
    public void perform() {
        System.out.println("Hello World!");
    }


}
