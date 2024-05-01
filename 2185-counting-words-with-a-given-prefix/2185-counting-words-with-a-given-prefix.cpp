struct TrieNode {
    char data;
    TrieNode* children[26];
    int prefixCount = 0;
};

class Solution {
private:
    TrieNode* createNode(char c) {
        TrieNode* node = new TrieNode();
        node->data = c;
        for (int i = 0; i < 26; ++i) {
            node->children[i] = nullptr;
        }
        return node;
    }
    
    void insert(TrieNode* root, string& s) {
        TrieNode* cur = root;
        for (auto &c : s) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = createNode(c);
            }
            cur = cur->children[c - 'a'];
            cur->prefixCount++;
        }
    }
    
    TrieNode* init() {
        TrieNode* root = new TrieNode();
        root->data = ' ';
        for (int i = 0; i < 26; ++i) {
            root->children[i] = nullptr;
        }
        return root;
    }
    
    int searchPrefix(TrieNode* root, string& prefix) {
        TrieNode* cur = root;
        for (auto &c : prefix) {
            if (cur->children[c - 'a'] == nullptr) {
                return 0;
            }
            
            cur = cur->children[c - 'a'];
        }
        return cur->prefixCount;
    }
    
public:
    int prefixCount(vector<string>& words, string pref) {
        TrieNode* root = init();
        for (auto& word : words) {
            insert(root, word);
        }
        return searchPrefix(root, pref);
    }
};