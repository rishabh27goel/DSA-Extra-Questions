package FactoryDesignPattern;
import java.util.Scanner;

public class FactoryDriver {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Create Electric Plan Factory
        ElectricPlanFactory electricPlanFactory = new ElectricPlanFactory();

        // Input Plan Type
        System.out.print("Enter the plan type : ");
        String planType = scanner.nextLine();

        // Create the object for the particular plan type
        ElectricPlan electricPlan = electricPlanFactory.createElectricPlan(planType);

        // Input number of units
        System.out.print("Enter number of units : ");
        int units = scanner.nextInt();

        try{
            electricPlan.getRate();
            electricPlan.calculateBill(units);
        }
        catch(Exception e){

            System.out.println("Enter a valid plan type !!!");
        }
    }
}
