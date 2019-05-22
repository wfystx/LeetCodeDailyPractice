class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==0) return;
        int l = 0, r = nums.size()-1, index = 0;
        while(index<=r){
            if(nums[index]==0){
                swap(nums[index], nums[l]);
                l++;
                index++;
            }else if(nums[index]==1) index++;
            else {
                swap(nums[index], nums[r]);
                r--;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        for(int i=0; i<=r; i++){
            while(nums[i]==2 && i<r) swap(nums[i], nums[r--]);
            while(nums[i]==0 && i>l) swap(nums[i], nums[l++]);
        }
    }
};