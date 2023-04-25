package BuilderDesignPattern.Builder;

import BuilderDesignPattern.Product.House;

public interface HouseBuilder {

    public void buildBasement();
    public void buildRoof();
    public void buildInterior();
    public void buildStructure();
    public House getHouse();
}
