class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, k, n, 1);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& temp, int k, int target, int pos){
        if(target == 0 && temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if(target > 0 && temp.size() < k){
            for(int i=pos; i<=9; i++){
                temp.push_back(i);
                helper(res, temp, k, target-i, i+1);
                temp.pop_back();
            }
        }
    }
};