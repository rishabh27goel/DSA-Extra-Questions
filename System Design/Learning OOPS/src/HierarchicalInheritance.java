public class HierarchicalInheritance {
    public static void main(String[] args) {

        Intern intern = new Intern();
        FullTime fullTime = new FullTime();
    }
}

class EmployeeClass
{
    EmployeeClass() {
        System.out.println("Employee Constructor !!");
    }
}

class Intern extends EmployeeClass
{
    Intern() {
        System.out.println("Intern Constructor !!");
    }
}

class FullTime extends EmployeeClass
{
    FullTime() {
        System.out.println("Full-Time Constructor !!");
    }
}

