class MinStack {
private:
    vector<int> data;
    vector<int> dm;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push_back(x);
        if(dm.empty() || dm.back()>=x) dm.push_back(x);
    }
    
    void pop() {
        if(data.back()==dm.back()) dm.pop_back();
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return dm.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */