class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(n+1,false);
        helper(res, temp, used, n, k, 1);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<bool>& used, int n, int k, int pos){
        if(temp.size()==k){
            res.emplace_back(temp);
            return;
        }
        for(int i=pos; i<=n; i++){
            if(!used[i]){
                if(temp.size()==0 || i>temp.back()){
                    used[i] = true;
                    temp.emplace_back(i);
                    helper(res, temp, used, n, k, pos+1);
                    temp.pop_back();
                    used[i] = false;
                }
            }
        }
    }
};