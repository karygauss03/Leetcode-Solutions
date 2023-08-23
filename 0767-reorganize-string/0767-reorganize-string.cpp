class Solution {
public:
    string reorganizeString(string& s) {
        vector<int> freq(26);
        vector<char> chars(26);
        for(char ch: s) {
            freq[ch-'a']++;
        }

        int n = s.length();
        int mi = 0;
        for(int i = 0; i < 26; ++i) {
            chars[i] = 'a' + i;
            if (freq[i] > (n+1)/2) return "";
            if (freq[i] > freq[mi]) {
                mi = i;
            }
        }

        // move max freq to the beginning.
        swap(freq[mi], freq[0]);
        swap(chars[mi], chars[0]);

        // 1. Fill ans in the following order: j=0,2,4,6,....
        // 2. Wrap around if j>=n; j=1,3,5,7....
        int j = 0;
        for(int i = 0; i < 26; ++i) {
            if (freq[i] == 0) continue;
            while(freq[i]-- > 0) {
                s[j] = chars[i]; 
                j += 2;
                if (j >= n) j = 1;
            }
        }
        return s;
    }
};