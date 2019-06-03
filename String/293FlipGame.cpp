class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for(int i=1; i<s.size(); i++){
            if(s[i] == '+' && s[i] == s[i-1]){
                    s[i] = s[i-1] = '-';
                    res.push_back(s);
                    s[i] = s[i-1] = '+';
            }
        }
        return res;
    }
    
};