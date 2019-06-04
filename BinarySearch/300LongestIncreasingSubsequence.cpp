class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail(nums.size(),0);
        int size = 0;
        for(auto n:nums){
            int i = 0, j = size;
            while(i != j){
                int m = i + (j - i)/2;
                if(tail[m] < n) i = m + 1;
                else j = m;
            }
            tail[i] = n;
            if(i == size) size ++;
        }
        return size;
    }
};