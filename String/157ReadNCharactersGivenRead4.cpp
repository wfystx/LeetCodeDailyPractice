// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        while(cnt < n){
            int m = read4(buf + cnt);
            cnt += m;
            if(m < 4) break;
        }
        return min(n, cnt);
    }
};