abstract class A{
    void show()
    {
        System.out.println("Base class non abstract class");
    }
    abstract void print();
}

class B extends A{
    void print()
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
        obj.show();
    }
}
