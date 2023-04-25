package BuilderDesignPattern.Product;

public class House {

    // Data Members
    private String basement;
    private String roof;
    private String interior;
    private String structure;


    // Setter Functions
    public void setBasement(String basement) {
        this.basement = basement;
    }
    public void setRoof(String roof) {
        this.roof = roof;
    }
    public void setInterior(String interior) {
        this.interior = interior;
    }
    public void setStructure(String structure) {
        this.structure = structure;
    }

    // Getter Functions
    public String getBasement() {
        return basement;
    }
    public String getRoof() {
        return roof;
    }
    public String getInterior() {
        return interior;
    }
    public String getStructure() {
        return structure;
    }
}
