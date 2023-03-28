public class SingleInheritance {

    public static void main(String []args){

        Developer developer = new Developer();
        developer.work();
    }
}

class Developer extends Employee
{
    Developer(){

        System.out.println("Developer Constructor !!");
    }
}

class Employee
{
    int employeeId;
    String employeeName;

    Employee() {
        System.out.println("Employee Constructor !!");
    }

    void work() {
        System.out.println("Employee is working !!");
    }
}
