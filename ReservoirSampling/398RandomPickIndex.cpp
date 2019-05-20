class Solution {
private:
    vector<int> n;
public:
    Solution(vector<int>& nums) {
        n = nums;
    }
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for(int i=0; i<n.size(); i++){
            if(n[i]==target){
                cnt++;
                if(rand() % cnt == 0) res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */