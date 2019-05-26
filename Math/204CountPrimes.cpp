class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> v(n, false);
        int cnt = 1;
        int upper = sqrt(n);
        for(int i=3; i<n; i+=2){
            if(!v[i]){
                cnt++;
                if(i>upper) continue;
                for(int j=i*i; j<n; j+=i){
                    v[j] = true;
                }
            } 
        }
        return cnt;
    }
};