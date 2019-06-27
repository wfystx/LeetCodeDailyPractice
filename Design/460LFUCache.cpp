class LFUCache {
private:
    unordered_map<int,pair<int,int>> m;
    unordered_map<int,list<int>::iterator> l;
    unordered_map<int,list<int>> fm; //freq to key list
    int minfre, size, cap;
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        update(key);
        return m[key].first;
    }
    
    void update(int key){
        fm[m[key].second].erase(l[key]);
        m[key].second++;
        fm[m[key].second].push_front(key);
        l[key] = fm[m[key].second].begin();
        
        if(fm[minfre].size() == 0) minfre++;
    }
    
    void evict(){
        m.erase(fm[minfre].back());
        l.erase(fm[minfre].back());
        fm[minfre].pop_back();
        size--;
    }
    
    void put(int key, int value) {
        if(cap <= 0) return;
        if(m.count(key)){
            m[key].first = value;
            update(key);
            return;
        }
        if(size == cap) evict();
        m[key] = {value, 1};
        fm[1].push_front(key);
        l[key] = fm[1].begin();
        minfre = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */