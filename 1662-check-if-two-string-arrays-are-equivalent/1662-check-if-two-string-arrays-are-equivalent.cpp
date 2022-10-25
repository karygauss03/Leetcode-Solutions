class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        string s1 = "",s2 = "";
        for (int i = 0; i < n1; i++) s1 += word1[i];
        for (int i = 0; i < n2; i++) s2 += word2[i];
        return (s1 == s2);
    }
};