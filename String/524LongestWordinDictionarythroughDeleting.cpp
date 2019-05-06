class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string rev;
        int m=0, n=0;
        for(auto v:d){
            for(int m=0, n=0; m<s.size() && n<v.size(); m++){
                if(s[m]==v[n]) n++;
                if(n==v.size() && (rev.size()<v.size() || (rev.size()==v.size()) && v<rev)) rev = v;
            }
        }
        return rev;
    }
};