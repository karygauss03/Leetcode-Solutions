class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string cur = "";
        cur += sentence[0];
        int cnt = 1;
        for (int i = 1; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                bool flag = false;
                for (int j = 0; j < searchWord.size(); ++j) {
                    if (searchWord[j] != cur[j]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    return cnt;
                }
                ++cnt;
                cur = "";
            }
            else {
                cur += sentence[i];
            }
        }
        bool flag = false;
        for (int j = 0; j < searchWord.size(); ++j) {
            if (searchWord[j] != cur[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            return cnt;
        }
        return -1;
    }
};