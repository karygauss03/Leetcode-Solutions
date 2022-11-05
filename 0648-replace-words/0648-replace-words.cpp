class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        sort(dict.begin(), dict.end());
        int n = sentence.size();
        string tmp = "";
        string ans = "";
        for (int i = 0 ; i < n ; i++){
            if (sentence[i] == ' '){
                bool flag = false;
                for (auto &s : dict){
                    if (s == tmp.substr(0, s.size())){
                        ans += s;
                        ans += ' ';
                        flag = true;
                        break;
                    }
                }
                if (!flag){
                    ans += tmp;
                    ans += ' ';
                }
                tmp = "";
            }
            else {
                tmp += sentence[i];
            }
        }
        bool flag = false;
        for (auto &s : dict){
            if (s == tmp.substr(0, s.size())){
                ans += s;
                ans += ' ';
                flag = true;
            }
        }
        if (!flag){
            ans += tmp;
            ans += ' ';
        }
        return ans.substr(0, ans.size() - 1);
    }
};