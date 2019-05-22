class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()==0) return res;
        sort(intervals.begin(), intervals.end(), comp);
        res.emplace_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=res.back()[1]) res.back()[1] = max(res.back()[1],intervals[i][1]);
            else res.emplace_back(intervals[i]);
        }
        return res;
    }
};