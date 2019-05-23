class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = m + n - 1;
        m--; n--;
        while(n>=0){
            if(m>=0 && nums1[m]>=nums2[n]) nums1[s--] = nums1[m--];
            else nums1[s--] = nums2[n--];
        }
    }
};