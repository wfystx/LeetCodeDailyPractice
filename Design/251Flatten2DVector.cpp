class Vector2D {
private:
    vector<vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& v) {
        i = v.begin();
        iEnd = v.end();
    }
    
    int next() {
        hasNext();
        return (*i)[j++];
    }
    
    bool hasNext() {
        while(i != iEnd && j == (*i).size()){
            i++; j = 0;
        }
        return i != iEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */