class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int s1FrequencyMap[26] = {0};
        int s2FrequencyMap[26] = {0};
        int numDiffs = 0;

        for (int i = 0; i < s1.size(); i++) {
            char s1Char = s1[i];
            char s2Char = s2[i];

            if (s1Char != s2Char) {
                numDiffs++;
                if (numDiffs > 2) return false;
            }
            s1FrequencyMap[s1Char - 'a']++;
            s2FrequencyMap[s2Char - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (s1FrequencyMap[i] != s2FrequencyMap[i]) return false;
        }

        return true;
    }
};