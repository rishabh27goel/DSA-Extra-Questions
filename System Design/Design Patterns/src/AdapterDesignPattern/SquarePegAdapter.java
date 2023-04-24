package AdapterDesignPattern;

public class SquarePegAdapter extends RoundPeg{

    private SquarePeg squarePeg;

    // Constructor takes the class to be converted
    public SquarePegAdapter(SquarePeg squarePeg){

        this.squarePeg = squarePeg;
    }

    @Override
    public double getRadius() {

        return squarePeg.getSide() / Math.sqrt(2);
    }
}
