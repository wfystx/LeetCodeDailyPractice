class Solution {
private:
    vector<int> num;
public:
    Solution(vector<int>& nums) {
        num = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return num;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = num;
        for(int i=0; i<res.size(); i++){
            int r = rand() % (res.size()-i);
            swap(res[i+r], res[i]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */