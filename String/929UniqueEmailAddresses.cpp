class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        for(string& email:emails){
            size_t tmp = email.find("@");
            string local = email.substr(0,tmp);
            string domin = email.substr(tmp+1);
            for(auto j = local.begin(); j != local.end(); j++){
                if(*j == '.'){
                    local.erase(j); j--;
                }
                if(*j == '+'){
                    local.erase(j, local.end()); break;
                }
            }
            email = local + "@" + domin;
        }
        sort(emails.begin(), emails.end());
        emails.erase(unique(emails.begin(), emails.end()), emails.end());
        return emails.size();
    }
};