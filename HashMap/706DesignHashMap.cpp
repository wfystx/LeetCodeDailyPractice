class MyHashMap {
private:
    vector<int> keyVector;
    vector<int> valueVector;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int search = -1;
        for(int i=0; i<keyVector.size(); i++){
            if(keyVector[i]==key){
                search = i;
                break;
            }
        }
        if(search == -1){
            keyVector.push_back(key);
            valueVector.push_back(value);
        }else{
            valueVector[search] = value;
            cout << valueVector[search] << endl;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(int i=0; i<keyVector.size(); i++){
            if(keyVector[i]==key){
                return valueVector[i];
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int search = -1;
        for(int i=0; i<keyVector.size(); i++){
            if(keyVector[i]==key){
                search = i;
                break;
            }
        }
        if(search==-1) return;
        for(int i=search; i<keyVector.size()-1; i++){
            swap(keyVector[i], keyVector[i+1]);
            swap(valueVector[i], valueVector[i+1]);
        }
        keyVector.pop_back();
        valueVector.pop_back();
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */