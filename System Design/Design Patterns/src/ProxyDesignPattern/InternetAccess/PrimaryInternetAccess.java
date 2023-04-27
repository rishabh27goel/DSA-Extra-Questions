package ProxyDesignPattern.InternetAccess;

public class PrimaryInternetAccess implements OfficeInternetAccess{

    private String employeeName;

    public PrimaryInternetAccess(String employeeName){

        this.employeeName = employeeName;
    }

    @Override
    public void grantInternetAccess() {

        System.out.println("Internet access granted to " + employeeName);
    }
}
