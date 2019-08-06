class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for(int i = 0; i <= N; i++){
            string origin = to_string(i), after;
            bool flag = true;
            for(auto c:origin){
                if(c == '0' || c == '1' || c == '8') after += c;
                else if(c == '2') after += '5';
                else if(c == '5') after += '2';
                else if(c == '6') after += '9';
                else if(c == '9') after += '6';
                else {
                    flag = false;
                    break;
                }
            }
            if(after != origin && flag) cnt++;
        }
        return cnt;
    }
};