class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        sum = 0;
        len = 0;
    }
    
    double next(int val) {
        if(len < sz) len++;
        if(q.size() >= sz) {
            sum -= q.front();
            q.pop(); 
        }
        q.push(val);
        sum += val;
        return sum / len;
    }
private:
    queue<int> q;
    int sz, len;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */