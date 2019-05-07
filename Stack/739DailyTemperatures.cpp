class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty()) return T;
        stack<int> s;
        vector<int> rev(T.size());
        for(int i=0; i<T.size(); i++){
            while(!s.empty() && T[s.top()]<T[i]){
                rev[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return rev;
    }
};