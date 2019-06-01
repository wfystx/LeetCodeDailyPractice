class Solution {
public:
    string getHint(string secret, string guess) {
        int acnt = 0, bcnt = 0;
        vector<int> s(10,0), g(10,0);
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]) acnt ++;
            else{
                s[secret[i] - '0'] ++;
                g[guess[i] - '0'] ++;
            }
        }
        for(int i=0; i<s.size(); i++) bcnt += min(s[i], g[i]);
        return to_string(acnt) + "A" + to_string(bcnt) + "B";
    }
};