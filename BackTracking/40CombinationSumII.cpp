class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, candidates, target, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int pos){
        if(target==0) res.emplace_back(temp);
        if(target>0){
            for(int i=pos; i<candidates.size(); i++){
                if(i&&candidates[i]==candidates[i-1]&&i>pos) continue;
                temp.emplace_back(candidates[i]);
                helper(res, temp, candidates, target-candidates[i], i+1);
                temp.pop_back();
            }
        }
    }
};