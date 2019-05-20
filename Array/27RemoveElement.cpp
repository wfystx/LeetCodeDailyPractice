class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(auto i=nums.begin(); i!=nums.end(); i++){
            if(nums[k]==val){
                nums.erase(i--);
                k--;
            } 
            k++;
        }
        return nums.size();
        /*
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==val) cnt++;
            else nums[i-cnt] = nums[i];
        }
        return nums.size()-cnt;
        */
    }
};