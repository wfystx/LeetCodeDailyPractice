class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        for(int k=nums.size()-1, i=0, j=(nums.size()+1)/2; k>=0; k--)
            nums[k] = k%2 == 0 ? tmp[i++] : tmp[j++];
    }
};