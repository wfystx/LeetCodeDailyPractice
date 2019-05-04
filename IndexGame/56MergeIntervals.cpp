class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> rev;
        if(intervals.size()==0) return rev;
        sort(intervals.begin(), intervals.end(), comp);
        rev.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=rev.back()[1]){
                vector<int> temp;
                temp.push_back(rev.back()[0]);
                temp.push_back(max(rev.back()[1], intervals[i][1]));
                rev.pop_back();
                rev.push_back(temp);
            }else{
                rev.push_back(intervals[i]);
            }
        }
        return rev;
    }
};