package FacadeDesignPattern;

import FacadeDesignPattern.MobileShop.IphoneShop;
import FacadeDesignPattern.MobileShop.RealmeShop;
import FacadeDesignPattern.MobileShop.SamsungShop;

public class ShopKeeperFacade {

    // Data Members
    private IphoneShop iphoneShop;
    private SamsungShop samsungShop;
    private RealmeShop realmeShop;

    // Constructor
    public ShopKeeperFacade(){

        iphoneShop = new IphoneShop();
        samsungShop = new SamsungShop();
        realmeShop = new RealmeShop();
    }

    // Data Functions
    public void iphoneSell(){
        iphoneShop.modelNumber();
        iphoneShop.price();
    }
    public void samsungSell(){
        samsungShop.modelNumber();
        samsungShop.price();
    }
    public void realmeSell(){
        realmeShop.modelNumber();
        realmeShop.price();
    }
}
