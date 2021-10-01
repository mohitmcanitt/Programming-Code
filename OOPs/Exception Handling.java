public class Main {
    public static void main(String args[]) {
        int a=5;
        int b=0;

        try
        {
            int c=a/b;
        }
        catch(Exception e)
        {
            System.out.println(e);
        }

    }
}
/*

public class Main {
    public static void main(String args[]) {
        int a=5;
        int b=0;

        if(b==0)
        {
            throw new ArithmeticException();
        }
        System.out.println("Last Line");

    }
}

*/
