/**
 Solution:
*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        char *c;
        if(emails.size()==0) return 0;
        string local, domin;
        for(int i=0;i<emails.size();i++){
            c = (char*)emails[i].data();
            local = strtok(c, "@");
            domin = strtok(NULL, "@");
            for(auto j=local.begin(); j!=local.end(); j++){
                if(*j == '+'){
                    local.erase(j, local.end());
                    break;
                }
                if(*j == '.'){
                    local.erase(j);
                    j--;
                }
            }
            emails[i] = local + '@' + domin;
        }
        sort(emails.begin(),emails.end());
        emails.erase(unique(emails.begin(), emails.end()), emails.end());
        return emails.size();
    }
};