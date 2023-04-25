package BuilderDesignPattern.Builder;

import BuilderDesignPattern.Product.House;

public class TreeHouse implements HouseBuilder{

    // Data Members
    private House house;

    public TreeHouse(){
        this.house = new House();
    }

    @Override
    public void buildBasement() {
        house.setBasement("Tree House Basement");
    }
    @Override
    public void buildInterior() {
        house.setInterior("Tree House Interior");
    }
    @Override
    public void buildRoof() {
        house.setRoof("Tree House Roof");
    }
    @Override
    public void buildStructure() {
        house.setStructure("Tree House Structure");
    }

    @Override
    public House getHouse() {
        return house;
    }
}

