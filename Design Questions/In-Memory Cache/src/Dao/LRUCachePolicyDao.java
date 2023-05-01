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
            if (value == null)
                return null;

            // Else update the linked list order
            cacheDataList.remove(key);
            cacheDataList.addFirst(key);

            return value;
        }
        catch (Exception e){

            System.out.println("Data Fetch not possible");
        }

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

            return true;
        }
        catch (Exception e){

            System.out.println("Data Insertion not possible");
        }

        return false;
    }
    @Override
    public boolean delete(Object key) {

        if(cacheDataStore.size() == 0)
            return false;

        try {

            Object value = cacheDataStore.get(key);

            // No value deleted
            if(value == null)
                return false;

            cacheDataList.remove(key);
            cacheDataStore.remove(key);

            return true;
        }
        catch (Exception e){

            System.out.println("Data Deletion not possible");
        }

        return false;
    }
    @Override
    public boolean clear(){

        try {

            cacheDataList.clear();
            cacheDataStore.clear();

            return true;
        }
        catch (Exception e){

            System.out.println("Data Clearing not possible");
        }

        return false;
    }
}
