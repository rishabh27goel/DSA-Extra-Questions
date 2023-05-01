package Dao;

public interface CachePolicyDao {

    public void createCache(int size);
    public Object fetch(Object key);
    public boolean insert(Object key, Object value);
    public boolean delete(Object key);
    public boolean clear();
}
