package FacadeDesignPattern;

import java.util.Scanner;

public class FacadeDriver {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // Create shopkeeper object
        ShopKeeperFacade shopKeeperFacade = new ShopKeeperFacade();

        int choice = -1;

        do {
            System.out.println("---------- Main Menu ----------");
            System.out.println("1. iPhone");
            System.out.println("2. Samsung");
            System.out.println("3. Realme");
            System.out.println("4. Exit");

            System.out.print("Enter your choice : ");
            choice = scanner.nextInt();


            switch (choice) {

                case 1:
                    shopKeeperFacade.iphoneSell();
                    break;

                case 2:
                    shopKeeperFacade.samsungSell();
                    break;

                case 3:
                    shopKeeperFacade.realmeSell();
                    break;

                case 4:
                    break;

                default:
                    System.out.println("You Purchased Nothing");
                    break;
            }
        } while (choice != 4);
    }
}
