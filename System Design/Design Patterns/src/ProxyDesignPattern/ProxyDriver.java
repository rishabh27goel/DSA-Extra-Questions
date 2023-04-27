package ProxyDesignPattern;

import ProxyDesignPattern.InternetAccess.ProxyInternetAccess;

import java.util.Scanner;

public class ProxyDriver {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter employee name : ");
        String employeeName = scanner.nextLine();

        // Proxy Internet Access Object
        ProxyInternetAccess proxyInternetAccess = new ProxyInternetAccess(employeeName);
        proxyInternetAccess.grantInternetAccess();
    }
}
