package AdapterDesignPattern;

public class RoundHole {

    // Data Members
    private double radius;

    public RoundHole(int radius){

        this.radius = radius;
        System.out.println("Round Hole Created");
    }

    public double getRadius(){

        return radius;
    }

    public boolean canFit(RoundPeg roundPeg){

        System.out.println("Round Peg Radius : " + roundPeg.getRadius());

        return radius >= roundPeg.getRadius();
    }
}
