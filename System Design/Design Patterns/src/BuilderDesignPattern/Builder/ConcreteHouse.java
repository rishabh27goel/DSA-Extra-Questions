package BuilderDesignPattern.Builder;

import BuilderDesignPattern.Product.House;

public class ConcreteHouse implements HouseBuilder{

    // Data Members
    private House house;

    public ConcreteHouse(){
        this.house = new House();
    }

    @Override
    public void buildBasement() {
        house.setBasement("Concrete House Basement");
    }
    @Override
    public void buildInterior() {
        house.setInterior("Concrete House Interior");
    }
    @Override
    public void buildRoof() {
        house.setRoof("Concrete House Roof");
    }
    @Override
    public void buildStructure() {
        house.setStructure("Concrete House Structure");
    }

    @Override
    public House getHouse() {
        return house;
    }
}
