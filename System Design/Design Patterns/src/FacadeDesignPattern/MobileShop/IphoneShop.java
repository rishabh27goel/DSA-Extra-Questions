package FacadeDesignPattern.MobileShop;

public class IphoneShop implements MobileShop{

    @Override
    public void modelNumber() {
        System.out.println("Iphone 14");
    }
    @Override
    public void price() {
        System.out.println("Rs 135000");
    }
}
