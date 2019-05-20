class RandomizedCollection {
private:
    unordered_map<int,vector<int>> m;
    vector<pair<int,int>> v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = false;
        if(m.find(val)==m.end()) flag = true;
        m[val].emplace_back(v.size());
        v.emplace_back(pair<int,int>(val,m[val].size()-1));
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        pair<int,int> p = v.back();
        m[p.first][p.second] = m[val].back();
        v[m[val].back()] = p;
        m[val].pop_back();
        if(m[val].empty()) m.erase(val);
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */