class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                res.emplace_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return res;
    }
    /*
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto n:nums1) m[n]++;
        vector<int> res;
        for(auto n:nums2)
            if(m.find(n)!=m.end() && m[n]>0){
                res.emplace_back(n);
                m[n]--;
            }
        return res;
    }
    */
};