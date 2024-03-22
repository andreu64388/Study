package fundamentals;

public class ReverseCommandLineArguments {
    public static final String[] args = new String[] {"1", "2"};
    public static void main(String[] _args) {
        for (int i = args.length - 1; i >= 0; i--) {
            System.out.println(args[i]);
        }
    }
}

