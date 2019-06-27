class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        vector<int> parents(26);
        for(int i = 0; i < 26; i++) parents[i] = i;
        for(int i = 0; i < A.size(); i++)
            uni(parents, A[i] - 'a', B[i] - 'a');
        string res;
        for(auto c:S)
            res += (char)(find(parents, c - 'a') + 'a');
        return res;
    }
    int find(vector<int> parents, int x){
        if(parents[x] == x) return x;
        return find(parents, parents[x]);
    }
    void uni(vector<int>& parents, int c1, int c2){
        int p1 = find(parents, c1);
        int p2 = find(parents, c2);
        if(p1 < p2) parents[p2] = p1;
        else parents[p1] = p2;
    }
};