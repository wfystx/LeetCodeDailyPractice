class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto c:t) m[c]++;
        int cnt = t.size(), start = 0, end = 0, d = INT_MAX, head = 0;
        while(end<s.size()){
            if(m[s[end++]]-->0) cnt--;
            while(cnt==0){
                if(d>end-start){
                    head = start;
                    d = end - start;
                }
                if(m[s[start++]]++==0) cnt++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};