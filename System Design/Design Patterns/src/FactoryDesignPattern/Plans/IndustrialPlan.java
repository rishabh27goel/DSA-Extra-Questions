package FactoryDesignPattern.Plans;
import FactoryDesignPattern.ElectricPlan;

public class IndustrialPlan extends ElectricPlan {

    public void getRate(){

        this.rate = 5;
        System.out.println("Industrial Plan Rate is : " + this.rate);
    }
}
