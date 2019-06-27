class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0, mod = 1e9 +7, n = A.size();
        vector<int> left(n), right(n);
        stack<pair<int,int>> s1,s2;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            while(!s1.empty() && s1.top().first > A[i]){
                cnt += s1.top().second;
                s1.pop();
            } 
            left[i] = cnt;
            s1.push({A[i],cnt});
        }
        for(int i = n - 1; i >= 0; i--){
            int cnt = 1;
            while(!s2.empty() && s2.top().first >= A[i]){
                cnt += s2.top().second;
                s2.pop();
            } 
            right[i] = cnt;
            s2.push({A[i],cnt});
        }
        for(int i = 0; i < n; i++)
            res = (res + A[i] * left[i] * right[i]) % mod;
        return res;
    }
};