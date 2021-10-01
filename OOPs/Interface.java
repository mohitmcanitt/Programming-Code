interface  A{
    void print();
}

class B implements A{
    public void print()
    {
        System.out.println("Derived Class");
    }
}

public class Main {
    public static void main(String args[]) {
        // A obj=new A();
        // cann't create object of abstract class
        B obj=new B();
        obj.print();
    }
}
