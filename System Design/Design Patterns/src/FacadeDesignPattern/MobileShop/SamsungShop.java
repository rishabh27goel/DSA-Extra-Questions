package FacadeDesignPattern.MobileShop;

public class SamsungShop implements MobileShop{

    @Override
    public void modelNumber() {
        System.out.println("Samsung Galaxy Tab");
    }
    @Override
    public void price() {
        System.out.println("Rs 85000");
    }
}
