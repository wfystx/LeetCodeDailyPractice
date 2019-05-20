class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(int i=0; i<s.size(); i++){
            char t = s[i];
            if(t==']' || t==')' || t=='}'){
                if(v.empty()) return false;
                if(t==']' && v.back()=='[') v.pop_back();
                else if(t==')' && v.back()=='(') v.pop_back();
                else if(t=='}' && v.back()=='{') v.pop_back();
                else return false;
            }else v.push_back(t);
        }
        return v.empty() ? true : false;
    }
};