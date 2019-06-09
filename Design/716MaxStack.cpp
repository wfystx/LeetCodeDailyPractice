class MaxStack {
private:
    list<int> mylist;
    map<int,vector<list<int>::iterator>> m;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        mylist.push_front(x);
        m[x].push_back(mylist.begin());
    }
    
    int pop() {
        int x = mylist.front();
        m[x].pop_back();
        if(m[x].empty()) m.erase(x);
        mylist.pop_front();
        return x;
    }
    
    int top() {
        return mylist.front();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int x = m.rbegin()->first;
        auto it = m[x].back();
        mylist.erase(it);
        m[x].pop_back();
        if(m[x].empty()) m.erase(x);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */