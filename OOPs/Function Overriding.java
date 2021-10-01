// No concept of Virtual in case of function overrriding
class Student
{
    void print()
    {
        System.out.println("Base Class");
    } 
   
}
class Student_Details extends Student
{
    void print()
     {
        System.out.println("Derived Class");
    } 
}

public class Main {
    public static void main(String args[]) {
        Student p=new Student_Details();
        p.print();
    }
}
