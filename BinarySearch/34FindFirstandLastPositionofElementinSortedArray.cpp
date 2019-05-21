class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        vector<int> res;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target){
                int k = mid;
                while(k>=0 && nums[k]==target) k--;
                res.emplace_back(k+1);
                k = mid;
                while(k<nums.size() && nums[k]==target) k++;
                res.emplace_back(k-1);
                return res;
            }else if(nums[mid]>target) r = mid-1;
            else l = mid+1;
        }
        return {-1,-1};
        
        /* O(n)
        vector<int> res = {-1,-1};
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                int k = i;
                while(k<nums.size() && nums[k]==target) k++;
                res[0] = i; res[1] = k-1;
                break;
            }
            if(nums[i]>target) break;
        }
        return res;
        */
    }
};