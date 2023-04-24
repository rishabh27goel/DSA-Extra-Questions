package FactoryDesignPattern.Plans;
import FactoryDesignPattern.ElectricPlan;

public class CommercialPlan extends ElectricPlan {

    public void getRate(){

        this.rate = 4;
        System.out.println("Commercial Plan Rate is : " + this.rate);
    }
}
