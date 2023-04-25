package BuilderDesignPattern;

import BuilderDesignPattern.Builder.ConcreteHouse;
import BuilderDesignPattern.Builder.HouseBuilder;
import BuilderDesignPattern.Builder.TreeHouse;
import BuilderDesignPattern.Director.CivilEngineer;
import BuilderDesignPattern.Product.House;

public class BuilderDriver {
    public static void main(String[] args) {

        // Creating Tree House
        // HouseBuilder treeHouse = new TreeHouse();
        HouseBuilder concreteHouse = new ConcreteHouse();

        // Creating Civil Engineer
        // CivilEngineer civilEngineer = new CivilEngineer(treeHouse);
         CivilEngineer civilEngineer = new CivilEngineer(concreteHouse);

        // Construct the house
        civilEngineer.constructHouse();

        // House creation done
        House house = civilEngineer.getHouse();

        System.out.println("House Created : " + house);
        System.out.println("House Basement : " + house.getBasement());
        System.out.println("House Interior : " + house.getInterior());
        System.out.println("House Roof : " + house.getRoof());
        System.out.println("House Structure : " + house.getStructure());
    }
}
