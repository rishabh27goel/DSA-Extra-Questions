import Services.CacheServices;

import java.util.ArrayList;

public class InMemoryCacheDriver {
    public static void main(String[] args) {

        CacheServices cacheServices = CacheServices.getInstance();
        cacheServices.createCache(2, "lru");

        // Test Case
        cacheServices.insert("Hi", "How are you ?");
        cacheServices.insert("Hello", new ArrayList<>());
        // cacheServices.insert("Rishabh", 23);

        System.out.println(cacheServices.fetch("Hi"));
        System.out.println(cacheServices.fetch("Rishabh"));
        System.out.println(cacheServices.fetch("Hello"));

        cacheServices.delete("Hello");
        cacheServices.delete("Hi");
        cacheServices.delete("Hello");
        cacheServices.clear();

        /*
        cacheServices.insert("Hi", "How are you ?");
        cacheServices.insert("Hello", "Test 1223");

        System.out.println(cacheServices.fetch("Hi"));
        System.out.println(cacheServices.fetch("Hello"));
        System.out.println(cacheServices.fetch("Rishabh"));
         */
    }
}
