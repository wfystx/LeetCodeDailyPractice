class LRUCache {
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(!kv.count(key)) return -1;
        update(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if(kv.size() == sz && !kv.count(key)) evict();
        update(key);
        kv[key] = value;
    }
    void update(int key){
        if(kv.count(key)) lru.erase(m[key]);
        lru.push_front(key);
        m[key] = lru.begin();
    }
    void evict(){
        m.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
private:
    int sz;
    list<int> lru;
    unordered_map<int,list<int>::iterator> m;
    unordered_map<int,int> kv;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */