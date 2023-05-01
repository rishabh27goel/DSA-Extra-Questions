package Models;

import Dao.CachePolicyDao;

public class Cache {

    private int size;
    private CachePolicyDao evictionPolicy;

    public Cache(int size, CachePolicyDao evictionPolicy){

        System.out.println("Cache is created");

        this.size = size;
        this.evictionPolicy = evictionPolicy;
    }

    // Getters / Setters
    public int getSize() {
        return size;
    }

    public CachePolicyDao getEvictionPolicy() {
        return evictionPolicy;
    }
}
