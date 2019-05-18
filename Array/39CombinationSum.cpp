class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, candidates, target, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int> candidates, int target, int start){
        if(target>0){
            for(int i=start; i<candidates.size() && target>=candidates[i]; i++){
                temp.push_back(candidates[i]);
                helper(res, temp, candidates, target-candidates[i], i);
                temp.pop_back();
            }
        }else if(target==0) res.push_back(temp);
    }
};