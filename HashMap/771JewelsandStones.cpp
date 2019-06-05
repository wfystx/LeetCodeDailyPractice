class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> m(J.begin(), J.end());
        int cnt = 0;
        for(auto s:S) if(m.count(s)) cnt++; 
        return cnt;
    }
};