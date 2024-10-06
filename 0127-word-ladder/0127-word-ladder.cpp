class Solution {
private:
    unordered_map<string, bool> vis;
    queue<string> q;
    string tmp;
    void checkNextWords(string cur) {
        for (int i = 0; i < cur.size(); ++i) {
            tmp = cur;
            for (int j = 0; j < 26; ++j) {
                tmp[i] = 'a' + j;
                if (vis.find(tmp) != vis.end() && !vis[tmp]) {
                    q.push(tmp);
                    vis[tmp] = true;
                }
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto &w : wordList) {
            vis[w] = false;
        }
        if (vis.find(endWord) == vis.end()) {
            return 0;
        }

        q.push(beginWord);
        int ans = 1, sz;
        string cur;
        while (!q.empty()) {
            sz = q.size();
            while (sz--) {
                cur = q.front();
                q.pop();
                if (cur == endWord) {
                    return ans;
                }
                checkNextWords(cur);
            }
            ++ans;
        }
        return 0;
    }
};