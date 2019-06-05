class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left = 0, right = m;
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        while(left <= right){
            int i = (left + right) / 2, j = (m + n + 1) / 2 - i;
            if(i && nums1[i-1] > nums2[j]) right = i - 1;
            else if(i < m && nums2[j-1] > nums1[i]) left = i + 1;
            else{
                int lmax = i == 0 ? nums2[j-1] : (j == 0 ? nums1[i-1] : max(nums1[i-1],nums2[j-1]));
                if((m + n) % 2) return lmax;
                int rmin = i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i],nums2[j]));
                return (lmax + rmin) / 2.0;
            }
        }
        return 0.0;
    }
};