struct TrieNode {
    TrieNode* next[26] = {};
    int cnt = 0;
};

class Solution {
    // Initialize the root node of the trie.
    TrieNode root;

public:
    // Insert function for the word.
    void insert(string word) {
        auto node = &root;
        for (char c : word) {
            // If new prefix, create a new trie node.
            if (!node->next[c - 'a']) {
                node->next[c - 'a'] = new TrieNode();
            }
            // Increment the count of the current prefix.
            node->next[c - 'a']->cnt++;
            node = node->next[c - 'a'];
        }
    }
    // Calculate the prefix count using this function.
    int count(string s) {
        auto node = &root;
        int ans = 0;
        // The ans would store the total sum of counts.
        for (char c : s) {
            ans += node->next[c - 'a']->cnt;
            node = node->next[c - 'a'];
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int N = words.size();
        // Insert words in trie.
        for (int i = 0; i < N; i++) {
            insert(words[i]);
        }
        vector<int> scores(N, 0);
        for (int i = 0; i < N; i++) {
            // Get the count of all prefixes of given string.
            scores[i] = count(words[i]);
        }
        return scores;
    }
};