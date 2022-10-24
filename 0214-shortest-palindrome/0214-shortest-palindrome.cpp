class Solution {
private:
    bool pal(string s, int i, int j){
        for(; i < j; i++, j--){
            if(s[i] != s[j])
                return 0;
        }
        return 1;
    }
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> v(n + 1, 0);
        for (int i = 1 ; i <= n ; i++){
            v[i] += v[i - 1] + (s[i - 1] - 'a');
        }
        string ans;
        for (int i = n ; i >= 1 ; i--){
            if((i % 2 == 0 && v[i/2] == v[i] - v[i/2]) || (i % 2 != 0 && v[i/2] == v[i] - v[i/2 + 1])){
                if(pal(s,0,i-1)){
                    ans = s.substr(i);
                    reverse(ans.begin(), ans.end());
                    break;
                }
            }
        }
        return ans + s;
    }
};