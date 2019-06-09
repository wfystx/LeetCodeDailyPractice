class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        
        for(auto path:paths){
            istringstream is(path);
            string s, root;
            getline(is, root, ' ');
            while(getline(is, s, ' ')){
                string filename = root + '/' + s.substr(0, s.find('('));
                string content = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                m[content].push_back(filename);
            }
        }
        for(auto item:m)
            if(item.second.size() > 1) res.push_back(item.second);
        return res;
    }
};