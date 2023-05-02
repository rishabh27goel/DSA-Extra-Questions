package Dao;

import Models.Cache;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class LRUCachePolicyDao implements CachePolicyDao {

    private static LRUCachePolicyDao instance = null;
    private Cache cache;
    private Map<Object, Object> cacheDataStore;
    private LinkedList<Object> cacheDataList;

    private LRUCachePolicyDao(){


    }

    public static LRUCachePolicyDao getInstance(){

        if(instance == null)
            instance = new LRUCachePolicyDao();

        return instance;
    }

    @Override
    public void createCache(int size) {

        this.cacheDataStore = new HashMap<>();
        this.cacheDataList = new LinkedList<>();
        this.cache = new Cache(size, getInstance());
    }
    @Override
    public Object fetch(Object key) {

        try {
            Object value = cacheDataStore.get(key);

            // If value is not found
            if (value == null){

                System.out.print("No data present with the key : ");
                return null;
            }

            // Else update the linked list order
            cacheDataList.remove(key);
            cacheDataList.addFirst(key);

            System.out.print("Data present in the data store : ");
            return value;
        }
        catch (Exception e){

            System.out.println("Data Fetch not possible");
        }

        System.out.print("No data present with the key : ");
        return null;
    }
    @Override
    public boolean insert(Object key, Object value) {

        try {
            // If size of cache is full
            if (cacheDataStore.size() >= cache.getSize()) {

                Object last = cacheDataList.removeLast();
                cacheDataStore.remove(last);
            }

            // Now either update value or add new
            cacheDataList.remove(key);
            cacheDataList.addFirst(key);
            cacheDataStore.put(key, value);

            System.out.println("Data inserted successfully");
            return true;
        }
        catch (Exception e){

            System.out.println("Data Insertion not possible");
            return false;
        }
    }
    @Override
    public boolean delete(Object key) {

        if(cacheDataStore.size() == 0){

            System.out.println("Data store is empty");
            return false;
        }

        try {

            Object value = cacheDataStore.get(key);

            // No value deleted
            if(value == null){

                System.out.println("No key found to delete");
                return false;
            }

            cacheDataList.remove(key);
            cacheDataStore.remove(key);

            System.out.println("Key deleted from data store");
            return true;
        }
        catch (Exception e){

            System.out.println("Data Deletion not possible");
            return false;
        }
    }
    @Override
    public boolean clear(){

        try {

            cacheDataList.clear();
            cacheDataStore.clear();

            System.out.println("Data store reset successful");
            return true;
        }
        catch (Exception e) {

            System.out.println("Data Clearing not possible");
            return false;
        }
    }
}
