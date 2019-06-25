class MyHashSet {
private:
    vector<int> s;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(contains(key)) return;
        s.push_back(key);
    }
    
    void remove(int key) {
        for(int i = 0; i < s.size(); i++) if(s[i] == key) s.erase(s.begin() + i); 
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int i:s) if(i == key) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */