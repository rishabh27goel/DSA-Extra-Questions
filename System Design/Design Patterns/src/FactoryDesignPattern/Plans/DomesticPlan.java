package FactoryDesignPattern.Plans;
import FactoryDesignPattern.ElectricPlan;

public class DomesticPlan extends ElectricPlan {

    public void getRate(){

        this.rate = 3;
        System.out.println("Domestic Plan Rate is : " + this.rate);
    }
}
