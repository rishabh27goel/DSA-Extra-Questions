package FactoryDesignPattern;

public abstract class ElectricPlan {

    // Data Member
    protected int rate;

    // Data Function
    public abstract void getRate();

    public void calculateBill(int units){

        System.out.println("Bill Information: ------------");
        System.out.println("Rate is : " + this.rate);
        System.out.println("Units : " + units);
        System.out.println("Total Bill : " + (this.rate * units));
    }
}
