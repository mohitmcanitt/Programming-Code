
class Student
{
    int age;
    String name;

    Student(int age,String name)
    {
        this.age=age;
        this.name=name;
    }
}
class Student_Details extends Student
{
    String city;
    String state;
    String pincode;

    Student_Details(String city,String state,String picode)
    {
        super(24,"Mohit");
        this.city=city;
        this.state=state;
        this.pincode=pincode;
    }
     void print()
    {
        System.out.println(name+" "+age);
    }
}

public class Main {
    public static void main(String args[]) {
        Student_Details p=new Student_Details("Patna","Bihar","801102");
        p.print();
    }
}
