/**
 Solution:
 Don't really know how to come up with such an idea.
*/
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s ,i);
    }
    string helper(string s, int& i){
        string res;
        while(i<s.size() && s[i]!=']'){
            if(!isdigit(s[i])) res+=s[i++];
            else{
                int n = 0;
                while(i<s.size() && isdigit(s[i])) n = n*10 + s[i++] - '0';
                i++;
                string t = helper(s, i);
                i++;

                while(n-->0) res+=t;
                
            }
        }
        return res;
    }
};