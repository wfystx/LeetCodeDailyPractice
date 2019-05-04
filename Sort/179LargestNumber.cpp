class Solution {
public:
    static bool comp(string a, string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> rev;
        for(auto n:nums){
            rev.push_back(to_string(n));
        }
        sort(rev.begin(), rev.end(), comp);
        string res = "";
        for(auto r:rev){
            res+=r;
        }
        while(res[0]=='0' && res.size()>1) res = res.substr(1, res.size()-1);
        return res;
        
    }
};