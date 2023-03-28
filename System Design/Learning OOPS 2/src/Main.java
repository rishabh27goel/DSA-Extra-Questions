public class Main {
    public static void main(String[] args) {

        GetterSetter getterSetter = new GetterSetter();

        // Can we used as it is private
        // getterSetter.age = "30";

        getterSetter.setAge(30);
        System.out.println("Age is : " + getterSetter.getAge());
    }
}

class GetterSetter
{
    private int age;
    private int weight;

    // Getters
    public int getAge() {
        return this.age;
    }

    public int getWeight() {
        return this.weight;
    }

    // Setters

    public void setAge(int age) {
        this.age = age;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }
}
