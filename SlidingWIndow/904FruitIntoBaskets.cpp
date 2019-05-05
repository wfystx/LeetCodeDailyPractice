/**
 Solution:
 Sliding Window
*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> m;
        int rev = 0;
        for(int i=0, j=0; j<tree.size(); j++){
            m[tree[j]]++;
            if(m.size()>2){
                m[tree[i]]--;
                if(m[tree[i]]==0) m.erase(tree[i]);
                i++;
            }
            rev = max(rev, j-i+1);
        }
        return rev;
    }
};