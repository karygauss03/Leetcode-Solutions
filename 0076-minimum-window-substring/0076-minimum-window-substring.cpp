class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp,check;
        for (auto i : t) {
            mp[i]++;
        }
        for (auto i : s) {
            check[i]++;
        }
        for (auto i : mp) {
            if (i.second > check[i.first])
                return "";
        }
        int len = mp.size(), i = 0, j = 0, cnt = len;
        string ans = s;
        while (j<s.length()) {
            if (mp.count(s[j])) {
                mp[s[j]]--;
                if (!mp[s[j]])
                    cnt--;
            }
            if (!cnt) {
                while (!cnt) {
                    string temp = s.substr(i, j - i + 1);
                    ans = temp.length() < ans.length() ? temp : ans;
                    if (mp.count(s[i]))
                        mp[s[i]]++;
                    if (mp.count(s[i]) and mp[s[i]] > 0)
                    {
                        cnt++;
                        i++;
                        break;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};