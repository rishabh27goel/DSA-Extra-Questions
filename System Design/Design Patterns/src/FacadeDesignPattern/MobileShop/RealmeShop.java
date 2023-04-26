package FacadeDesignPattern.MobileShop;

public class RealmeShop implements MobileShop{

    @Override
    public void modelNumber() {
        System.out.println("Realme 9i");
    }
    @Override
    public void price() {
        System.out.println("Rs 65000");
    }
}
