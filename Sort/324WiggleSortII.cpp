/**
 Solution:
 Sort, divide into 2 parts. insert them together.
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int m = 0, n = (nums.size()+1)/2;
        for(int k=nums.size()-1; k>=0; k--){
            nums[k] = k%2==0 ? temp[m++] : temp[n++];
        }
    }
};