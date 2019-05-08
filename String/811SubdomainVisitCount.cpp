class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        char *n;
        unordered_map<string, int> m;
        for(int i=0; i<cpdomains.size(); i++){
            n = (char*)cpdomains[i].data();
            int num = atoi(strtok(n, " "));
            string domain = strtok(NULL, " ");
            m[domain]+=num;
            for(int j=0; j<domain.size(); j++){
                if(domain[j]=='.') m[domain.substr(j+1)]+=num;
            }
        }
        vector<string> rev;
        for(auto item:m){
            rev.push_back(to_string(item.second)+" "+item.first);
        }
        return rev;
    }
};