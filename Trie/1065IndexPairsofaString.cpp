class TrieNode {
public:
    TrieNode* child[26];
    bool is_word;
    TrieNode(){
        memset(child, 0, sizeof(child));
        is_word = false;
    }
};
class Solution {
private:
    TrieNode* root;
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        root = new TrieNode();
        vector<vector<int>> res;
        for(auto word:words) insert(word);
        for(int i = 0; i < text.size(); i++){
            TrieNode* cur = root;
            string str;
            for(int j = i; j < text.size(); j++){
                if(cur->child[text[j] - 'a'] == nullptr) break;
                str += text[j];
                cur = cur->child[text[j] - 'a'];
                if(cur->is_word) res.push_back({i, j});
            }
        }
        return res;
    }
    
    void insert(string word){
        TrieNode* cur = root;
        for(auto c:word){
            if(cur->child[c - 'a'] == nullptr) cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }
        cur->is_word = true;
    }
    
    bool find(string word){
        TrieNode* cur = root;
        for(auto c:word){
            if(cur->child[c - 'a'] == nullptr) return false;
            cur = cur->child[c - 'a'];
        }
        return cur->is_word;
    }
};