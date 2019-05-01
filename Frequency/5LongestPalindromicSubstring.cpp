/**
 Solution:
 Expand Around Center. Observe that a palindrome mirrors around its center.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        string rev = "";
        for(int i=0; i<s.size(); i++){
            rev = helper(s, i, i).size()>rev.size() ? helper(s, i, i) : rev;
            rev = helper(s, i, i+1).size()>rev.size() ? helper(s, i, i+1) : rev;
        }
        return rev;
    }
    string helper(string s, int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
};