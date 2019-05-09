class Solution {
public:
    int myAtoi(string str) {
        set<char> num = {'1','2','3','4','5','6','7','8','9','0'};
        long rev = 0;
        int flag = 0;
        int i = 0;
        while(str[i]==' ') i++;
        if(str[i]=='-'){
            flag = 1;
            i++;
        }else if(str[i]=='+'){
            i++;
        }else if(num.find(str[i])==num.end()) return 0;
        for(i; i<str.size(); i++){
            if(num.find(str[i])==num.end()){
                return flag==0 ? rev : -rev;
            }else rev = rev*10+str[i]-'0';
            if(rev>INT_MAX && flag == 0) return INT_MAX;
            else if(rev>INT_MAX && flag == 1) return INT_MIN;
            //cout << rev << endl;
        }
        return flag==0 ? rev : -rev;
    }
};