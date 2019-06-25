class TrieNode {
public:
    TrieNode* child[26];
    bool is_word;
    TrieNode(){
        memset(child, 0, sizeof(child));
        is_word = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(auto c:word){
            if(node->child[c - 'a'] == nullptr) node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->is_word = true;
    }
    string replace(string word){
        TrieNode* node = root;
        string r;
        for(auto c:word){
            r += c;
            if(node->child[c - 'a'] != nullptr){
                if(node->child[c - 'a']->is_word == true) return r;
                node = node->child[c - 'a'];
            }else return word;
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* trie = new Trie();
        for(auto s:dict) trie->insert(s);
        istringstream is(sentence);
        string word, res;
        while(is >> word) res += " " + trie->replace(word);
        return res.substr(1);
    }
};