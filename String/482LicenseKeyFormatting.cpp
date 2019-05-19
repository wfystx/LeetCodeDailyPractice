class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        S.erase(remove(S.begin(),S.end(),'-'),S.end());
        int cnt = 0;
        for(int i=S.size()-1; i>=0; i--){
            S[i] = toupper(S[i]);
            cnt++;
            if(cnt==K && i!=0) {
                S.insert(i,1,'-');
                cnt = 0;
            }
        }
        return S;
    }
};