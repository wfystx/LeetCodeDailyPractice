class TrieNode{
public:
    TrieNode *next[26];
    bool is_word;
    TrieNode(){
        memset(next, 0, sizeof(next));
        is_word = false;
    }
};
class WordDictionary {
private:
    TrieNode *root;
    bool find(string word, TrieNode *node){
        for(int i=0; i<word.size() && node; i++){
            if(word[i] != '.') node = node->next[word[i] - 'a'];
            else{
                TrieNode *tmp = node;
                for(int j=0; j<26; j++){
                    node = tmp->next[j];
                    if(find(word.substr(i+1), node)) return true;
                }
            }
        }
        return node && node->is_word;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(int i=0; i<word.size(); i++){
            if(!p->next[word[i] - 'a'])
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */