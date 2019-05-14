class MinStack {
private:
    vector<int> stack;
    vector<int> mini;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if(!mini.empty() && x<=mini.back()) mini.push_back(x);
        else if(mini.empty()) mini.push_back(x);
    }
    
    void pop() {
        if(mini.back()==stack.back()) mini.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return mini.back();
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