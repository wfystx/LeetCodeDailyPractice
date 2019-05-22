class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][1]<newInterval[0]){
                res.emplace_back(intervals[i]);
            }else if(intervals[i][0]>newInterval[1]){
                res.emplace_back(newInterval);
                for(int j=i; j<intervals.size(); j++) res.emplace_back(intervals[j]);
                return res;
            }else newInterval = merge(intervals[i], newInterval);
        }
        res.emplace_back(newInterval);
        return res;
    }
private:
    vector<int> merge(vector<int>& i1, vector<int>& i2){
        return vector<int>({min(i1[0],i2[0]),max(i1[1],i2[1])});
    }
};