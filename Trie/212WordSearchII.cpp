class TrieNode{
public:
    TrieNode *next[26];
    bool is_word;
    TrieNode(){
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};
class Trie{
private:
    TrieNode *root;
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root = new TrieNode();
        for(auto w:words) addWord(w);
    }
    void addWord(string word){
        TrieNode *p = root;
        for(int i=0; i<word.size(); i++){
            if(!p->next[word[i] - 'a'])
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode *root = trie->getRoot();
        unordered_set<string> result;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                dfs(board, i, j, root, "", result);
        vector<string> res;
        for(auto r:result) res.push_back(r);
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, string word, unordered_set<string>& result){
        if(i<0||i>=board.size()||j<0||j>=board[0].size() || board[i][j]=='#') return;
        if(root->next[board[i][j] - 'a']){
            word = word + board[i][j];
            root = root->next[board[i][j] - 'a'];
            if(root->is_word) result.insert(word);
            char c = board[i][j];
            board[i][j] = '#';
            dfs(board, i+1, j, root, word, result);
            dfs(board, i, j+1, root, word, result);
            dfs(board, i-1, j, root, word, result);
            dfs(board, i, j-1, root, word, result);
            board[i][j] = c;
        }
    }
};