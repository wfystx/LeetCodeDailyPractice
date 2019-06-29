class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];
        stack<int> s;
        heights.push_back(0);
        int i = 0, n = heights.size(), res = 0;
        while(i < n){
            if(s.empty() || heights[i] > heights[s.top()]) s.push(i++);
            else{
                int h = heights[s.top()];
                s.pop();
                int j = s.empty() ? -1 : s.top();
                res = max(res, h * (i - j - 1));
            }
        }
        return res;
    }
};