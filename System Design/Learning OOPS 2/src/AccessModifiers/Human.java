package AccessModifiers;

public class Human
{
    private int age;
    public int height;
//    int height;
    protected int weight;

    public Human(){

        System.out.println("Human Constructor");
        this.age = 20;
        this.height = 180;
        this.weight = 80;
        System.out.println("Age is : " + this.age);
    }
}