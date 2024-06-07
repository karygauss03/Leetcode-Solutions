struct TrieNode {
    char data;
    bool isPrefix;
    TrieNode* children[26];
};

class Solution {
private:
    vector<string> tokenizer(string& line) {
        vector<string> tokens;
        stringstream check1(line);
        string intermediate;
        while (getline(check1, intermediate, ' ')) {
            tokens.push_back(intermediate);
        }
        return tokens;
    }

public:
    TrieNode nodepool[100000];  // Pool of 100K TrieNodes
    TrieNode* root;             // Root of Trie
    int poolcount;              // Always points to next free TrieNode

    void init() {
        poolcount = 0;
        root = &nodepool[poolcount++];
        root->data = '/';
        root->isPrefix = false;
        for (int i = 0; i < 26; ++i) {
            root->children[i] = nullptr;
        }
    }

    TrieNode* getNode(char c) {
        TrieNode* node = &nodepool[poolcount++];
        node->data = c;
        node->isPrefix = false;
        for (int i = 0; i < 26; ++i) {
            node->children[i] = nullptr;
        }
        return node;
    }

    void insert(string& word) {
        TrieNode* current = root;
        for (auto& c : word) {
            if (current->children[c - 'a'] == nullptr) {
                current->children[c - 'a'] = getNode(c);
            }
            current = current->children[c - 'a'];
        }
        current->isPrefix = true;
    }

    bool search(string& prefix) {
        TrieNode* current = root;
        for (char& c : prefix) {
            if (current->children[c - 'a'] == nullptr) {
                return false;
            }
            current = current->children[c - 'a'];
        }
        return current->isPrefix;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        init();
        for (auto& word : dictionary) {
            insert(word);
        }

        string ans = "";
        vector<string> tokens = tokenizer(sentence);

        for (auto& token : tokens) {
            bool found = false;
            string prefix;
            TrieNode* current = root;
            for (int i = 1; i <= token.size(); ++i) {
                string prefix = token.substr(0, i);
                if (search(prefix)) {
                    ans += prefix;
                    found = true;
                    break;
                }
            }

            if (found) {
                ans += prefix;
            } else {
                ans += token;
            }
            ans += " ";
        }

        return ans.substr(0, ans.size() - 1);
    }
};
