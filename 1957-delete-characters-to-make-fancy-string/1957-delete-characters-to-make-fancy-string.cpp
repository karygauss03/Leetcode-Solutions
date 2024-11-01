class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        int frequency = 1;
        string ans = "";
        ans.push_back(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == prev) {
                frequency++;
            } else {
                prev = s[i];
                frequency = 1;
            }

            if (frequency < 3) ans.push_back(s[i]);
        }

        return ans;
    }
};