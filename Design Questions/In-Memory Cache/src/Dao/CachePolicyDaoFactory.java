package Dao;

public class CachePolicyDaoFactory {
    public CachePolicyDao createCachePolicyDao(String policyType){

        final String LRU = "lru";

        switch (policyType) {

            case LRU :
                return LRUCachePolicyDao.getInstance();

            default:
                return null;
        }
    }
}