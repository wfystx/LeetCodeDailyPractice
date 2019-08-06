class Solution {
public:
    static bool cmp(string& a, string& b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto n:nums) v.push_back(to_string(n));
        sort(v.begin(), v.end(), cmp);
        string res;
        for(auto s:v) res += s;
        while(res.size() > 1 && res[0] == '0') res = res.substr(1);
        return res;
    }
};