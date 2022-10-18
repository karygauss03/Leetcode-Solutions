class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string ans = "1";
        for (int i = 0 ; i < n - 1 ; ++i){
            string tmp = "";
            for (int j = 0 ; j < ans.size() ; ++j){
                int cnt = 1;
                while (j + 1 < ans.size() && ans[j] == ans[j + 1]){
                    j++;
                    cnt++;
                }
                tmp.push_back(cnt + '0');
                tmp.push_back(ans[j]);
            }
            ans = tmp;
        }
        return ans;
    }
};