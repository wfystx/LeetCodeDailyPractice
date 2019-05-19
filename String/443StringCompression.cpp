class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        while(i<chars.size()){
            chars[j] = chars[i];
            int cnt = 0;
            while(i<chars.size() && chars[i]==chars[j]){
                cnt++;
                i++;
            }
            if(cnt==1) j++;
            else{
                string str = to_string(cnt);
                for(auto c:str){
                    chars[++j] = c;
                }
                j++;
            }
        }
        return j;
    }
};