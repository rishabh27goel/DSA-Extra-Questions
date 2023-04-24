package FactoryDesignPattern;

import FactoryDesignPattern.Plans.CommercialPlan;
import FactoryDesignPattern.Plans.DomesticPlan;
import FactoryDesignPattern.Plans.IndustrialPlan;

public class ElectricPlanFactory {

    public ElectricPlan createElectricPlan(String planType){

        // Plan Type Constants
        final String DOMESTIC = "domestic";
        final String COMMERCIAL = "commercial";
        final String INDUSTRIAL = "industrial";


        switch (planType){

            case DOMESTIC :
                return new DomesticPlan();

            case COMMERCIAL:
                return new CommercialPlan();

            case INDUSTRIAL:
                return new IndustrialPlan();

            default:

                return null;
        }
    }
}
