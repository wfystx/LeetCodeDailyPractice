
class Solution {
public:
    static bool cmp(string s1, string s2){
        int i = s1.find(' ');
        int j = s2.find(' ');
        if(isalpha(s1[i+1]) && isalpha(s2[j+1])){
            if(s1.substr(i+1) == s2.substr(j+1)) return s1 < s2;
            else return s1.substr(i+1) < s2.substr(j+1);
        } 
        else{
            if(isalpha(s1[i+1])) return true;
            else return false;
        }
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};