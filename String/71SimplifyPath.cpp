class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        vector<string> stk;
        stringstream s(path);
        while(getline(s,temp,'/')){
            if(temp=="" || temp==".") continue;
            if(temp==".." && !stk.empty()) stk.pop_back();
            if(temp!="..") stk.emplace_back(temp);
        }
        for(auto str:stk) res += "/" + str;
        return res.empty() ? "/" : res;
    }
};