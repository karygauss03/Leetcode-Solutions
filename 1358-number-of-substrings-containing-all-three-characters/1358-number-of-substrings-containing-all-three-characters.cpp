class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        queue<int> a, b, c;
        
        for (int i = 0; i < n; ++i) {
            switch(s[i]) {
                case 'a':
                    a.push(i);
                    break;
                case 'b':
                    b.push(i);
                    break;
                default:
                    c.push(i);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a'){
                while (!b.empty() && b.front() < i) {
                    b.pop();
                }
                if (b.empty()) {
                    continue;
                }
                int bIndex = b.front();
                while (!c.empty() && c.front() < i) {
                    c.pop();
                }
                if (c.empty()) {
                    continue;
                }
                int cIndex = c.front();
                ans += (n - max(cIndex, bIndex));
            } 
            else if (s[i] == 'b'){
                while (!a.empty() && a.front() < i) {
                    a.pop();
                }
                if (a.empty()) {
                    continue;
                }
                int aIndex = a.front();
                while (!c.empty() && c.front() < i) {
                    c.pop();
                }
                if (c.empty()) {
                    continue;
                }
                int cIndex = c.front();
                ans += (n - max(cIndex, aIndex));
            }
            else{
                while (!a.empty() && a.front() < i) {
                    a.pop();
                }
                if (a.empty()) {
                    continue;
                }
                int aIndex = a.front();
                while (!b.empty() && b.front() < i) {
                    b.pop();
                }
                if (b.empty()) {
                    continue;
                }
                int bIndex = b.front();
                ans += (n - max(bIndex, aIndex));
            }
        }
        return ans;
    }
};