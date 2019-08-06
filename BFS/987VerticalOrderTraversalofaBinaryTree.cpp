/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int,vector<pair<int,int>>> mypair;
        int h = 0, v = 0;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{h,v}});
        while(!q.empty()){
            auto tmp = q.front(); q.pop();
            auto point = tmp.second;
            auto node = tmp.first;
            h = point.first;
            v = point.second;
            mypair[h].push_back({v, node->val});
            
            auto l = node->left, r = node->right;
            if(l) q.push({l, {h - 1, v + 1}});
            if(r) q.push({r, {h + 1, v + 1}});
        }
        
        res.resize(mypair.size());
        int idx = 0;
        for(auto item:mypair){
            auto vec = item.second;
            sort(vec.begin(), vec.end());
            for(auto val:vec){
                res[idx].push_back(val.second);
            }
            idx++;
        }
        return res;
    }
};