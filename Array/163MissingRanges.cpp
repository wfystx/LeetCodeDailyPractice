class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long pre = (long)lower - 1;
        for(int i=0; i<=nums.size(); i++){
            long cur = (i == nums.size() ? (long)upper + 1 : (long)nums[i]);
            if(cur - pre >= 2) res.push_back(get_range(pre + 1, cur - 1));
            pre = cur;
        }
        return res;
    }
    string get_range(int start, int end){
        return start==end? to_string(start) : to_string(start)+"->"+to_string(end);
    }
};