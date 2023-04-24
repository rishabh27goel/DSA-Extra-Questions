package AdapterDesignPattern;

public class AdapterDriver {
    public static void main(String[] args) {

        // Create a round hole
        RoundHole roundHole = new RoundHole(5);

        // Create a round peg
        RoundPeg smallRoundPeg = new RoundPeg(4);
        RoundPeg largeRoundPeg = new RoundPeg(7);

        System.out.println("Small Round Peg : " + roundHole.canFit(smallRoundPeg));
        System.out.println("Large Round Peg : " + roundHole.canFit(largeRoundPeg));

        // Create a square peg
        SquarePeg smallSquarePeg = new SquarePeg(5);
        SquarePeg largeSquarePeg = new SquarePeg(9);

        // Square Peg is not the default input for round hole
        // System.out.println("Small Round Peg : " + roundHole.canFit(smallSquarePeg));
        // System.out.println("Large Round Peg : " + roundHole.canFit(largeSquarePeg));

        // Use of Square Peg Adapter
        RoundPeg smallSquarePegWithAdapter = new SquarePegAdapter(smallSquarePeg);
        RoundPeg largeSquarePegWithAdapter = new SquarePegAdapter(largeSquarePeg);

         System.out.println("Small Square Peg : " + roundHole.canFit(smallSquarePegWithAdapter));
         System.out.println("Large Square Peg : " + roundHole.canFit(largeSquarePegWithAdapter));
    }
}
