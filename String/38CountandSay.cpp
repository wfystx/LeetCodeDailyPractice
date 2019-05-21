class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i=0; i<n-1; i++){
            string buf;
            for(int j=0; j<res.size(); j++){
                int cnt = 1;
                while(j+1<res.size() && res[j+1]==res[j]){
                    j++;
                    cnt++;
                }
                buf += (cnt +'0');
                buf += res[j];
            }
            res = buf;
        }
        return res;
    }
};