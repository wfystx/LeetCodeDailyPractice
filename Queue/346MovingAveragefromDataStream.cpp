class MovingAverage {
private:
    int tail;
    vector<int> data;
    int s;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        s = size;
        tail = -1;
    }
    
    double next(int val) {
        data.push_back(val);
        tail++;
        double rev = 0;
        if(data.size()<=s){
            for(int i=tail; i>=0; i--){
                rev += data[i];
            }
            rev /= (tail+1);
        }else{
            for(int i=tail; i>=data.size()-s; i--){
                rev += data[i];
            }
            rev /= s;
        }
        return rev;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */