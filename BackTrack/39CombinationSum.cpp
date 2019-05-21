class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, candidates, target, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int pos){
        if(target==0) res.emplace_back(temp);
        if(target>0){
            for(int i=pos; i<candidates.size(); i++){
                temp.emplace_back(candidates[i]);
                helper(res, temp, candidates, target-candidates[i], i);
                temp.pop_back();
            }
        }
    }
};