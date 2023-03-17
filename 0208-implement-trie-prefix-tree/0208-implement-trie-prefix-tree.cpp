class TrieNode{
public:
    bool isCompleteWord;
    TrieNode* children[26];

    TrieNode() {
        isCompleteWord = false; // when the word is complete (mark that node as true)
        memset(children, 0, sizeof(children)); // for 26 possible Childrens (for next letter)
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word){
            int idx = ch - 'a';
            if(node->children[idx]==NULL) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isCompleteWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->children[idx]==NULL) return false;
            node = node->children[idx];
        }
        return node->isCompleteWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
            int idx = ch - 'a';
            if(node->children[idx]==NULL) return false;
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */