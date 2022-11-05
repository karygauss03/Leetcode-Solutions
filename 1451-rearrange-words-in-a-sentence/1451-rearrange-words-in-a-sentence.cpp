class Solution {
public:
    string arrangeWords(string text) {
        int n = text.size();
        string ans = "", tmp = "";
        int first = 0;
        vector<pair<int, int>> a;
        for (int i = 0 ; i < n ; i++){
            if (text[i] == ' '){
                a.push_back(make_pair(tmp.size(), first));
                tmp = "";
                first = i + 1;
            }
            else {
                tmp += text[i];
            }
        }
        a.push_back(make_pair(tmp.size(), first));
        sort(a.begin(), a.end());
        for (auto &p : a){
            int sz = p.first;
            int index = p.second;
            ans += text.substr(index, sz);
            ans += ' ';
        }
        ans = ans.substr(0, ans.size() - 1);
        ans[0] = toupper(ans[0]);
        for (int i = 1 ; i < ans.size() ; i++){
            if (ans[i] != ' '){
                ans[i] = tolower(ans[i]);
            }
        }
        return ans;
    }
};