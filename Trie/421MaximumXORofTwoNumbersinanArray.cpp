struct TrieNode {
    int val;
    TrieNode* left;
    TrieNode* right;
    TrieNode(int x): val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode(0), *cur = root;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 31; j >= 0; j--){
                int tmp = nums[i] & (1 << j);
                if(tmp == 0){
                    if(!cur->right) cur->right = new TrieNode(0);
                    cur = cur->right;
                }else{
                    if(!cur->left) cur->left = new TrieNode(1);
                    cur = cur->left;
                }
            }
            cur = root;
        }
        int m = 0;
        for(int i = 0; i < nums.size(); i++){
            int res = 0;
            for(int j = 31; j >= 0; j--){
                int tmp = nums[i] & (1 << j);
                if(cur->left && cur->right){
                    if(tmp == 0) cur = cur->left;
                    else cur = cur->right;
                }else cur = cur->left ? cur->left : cur->right;
                res += tmp ^ (cur->val << j);
            }
            cur = root;
            m = max(m, res);
        }
        return m;
    }
};