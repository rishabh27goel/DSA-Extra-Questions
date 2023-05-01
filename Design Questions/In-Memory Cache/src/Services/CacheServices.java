package Services;

import Dao.CachePolicyDao;
import Dao.CachePolicyDaoFactory;

public class CacheServices {

    private static CacheServices instance = null;
    private CachePolicyDao cachePolicyDao;

    private CacheServices(){


    }

    public static CacheServices getInstance(){

        if(instance == null)
            instance = new CacheServices();

        return instance;
    }

    // Create cache method [to create cache memory]
    public void createCache(int size, String policyType){

        // Create the instance of Cache Policy Dao for particular policyType
        CachePolicyDaoFactory cachePolicyDaoFactory = new CachePolicyDaoFactory();

        cachePolicyDao = cachePolicyDaoFactory.createCachePolicyDao(policyType);
        cachePolicyDao.createCache(size);
    }

    // For fetching data if present
    public Object fetch(Object key){

        return cachePolicyDao.fetch(key);
    }

    // For inserting data in cache
    public boolean insert(Object key, Object value){

        return cachePolicyDao.insert(key, value);
    }

    // For deleting data from cache
    public boolean delete(Object key){

        return cachePolicyDao.delete(key);
    }

    // Clearing the cache
    public boolean clear() {

        return cachePolicyDao.clear();
    }
}
