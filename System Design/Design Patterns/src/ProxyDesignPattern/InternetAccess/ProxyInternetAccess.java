package ProxyDesignPattern.InternetAccess;

import java.util.ArrayList;
import java.util.Arrays;

public class ProxyInternetAccess implements OfficeInternetAccess{

    private ArrayList<String> members;
    private PrimaryInternetAccess primaryInternetAccess;
    private String employeeName;

    public ProxyInternetAccess(String employeeName){

        this.employeeName = employeeName;
        this.members = new ArrayList<String>(Arrays.asList("Rishabh", "Tom", "Harry", "Robert"));
    }

    @Override
    public void grantInternetAccess() {

        // Check for employee name in list of users
        if(checkForPermission(employeeName)){

            primaryInternetAccess = new PrimaryInternetAccess(employeeName);
            primaryInternetAccess.grantInternetAccess();
        }
        else{

            System.out.println("User can not be granted internet access");
        }
    }

    public boolean checkForPermission(String employeeName){

        for (String person : members){

            if(person.equalsIgnoreCase(employeeName)){

                return true;
            }
        }

        return false;
    }
}
