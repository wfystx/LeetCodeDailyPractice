class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size() - 1, n = arr2.size() - 1, carry = 0;
        vector<int> res;
        while(m >= 0 || n >= 0 || carry){
            carry += (m >= 0 ? arr1[m--] : 0) + (n >= 0 ? arr2[n--] : 0);
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while(res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};