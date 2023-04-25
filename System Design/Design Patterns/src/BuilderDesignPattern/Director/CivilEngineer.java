package BuilderDesignPattern.Director;

import BuilderDesignPattern.Builder.HouseBuilder;
import BuilderDesignPattern.Product.House;

public class CivilEngineer {

    // Data Member
    private HouseBuilder houseBuilder;

    public CivilEngineer(HouseBuilder houseBuilder){

        this.houseBuilder = houseBuilder;
    }

    public House getHouse(){

        return houseBuilder.getHouse();
    }

    public void constructHouse(){

        houseBuilder.buildBasement();
        houseBuilder.buildInterior();
        houseBuilder.buildStructure();
        houseBuilder.buildRoof();
    }
}
