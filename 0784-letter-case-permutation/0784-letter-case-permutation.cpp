class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();
        for (int i = 0 ; i < (1<<n) ; i++){
            string tmp = "";
            for (int j = 0 ; j < n ; j++){
                if (s[j] <= '9' || !((1<<j) & i)){
                    tmp += s[j];
                    continue;
                }
                if ((1<<j) & i){
                    if (s[j] <= 'Z'){
                        tmp += tolower(s[j]);
                    }
                    else {
                        tmp += toupper(s[j]);
                    }
                }
            }
            if (find(ans.begin(), ans.end(), tmp) == ans.end())
                ans.push_back(tmp);
        }
        return ans;
    }
};