class Solution {
private:
    vector<string> split(string str, char delimiter)
    {
        stringstream ss(str);
        vector<string> res;
        string token;
        while (getline(ss, token, delimiter)) {
            res.push_back(token);
        }
        return res;
    }
    public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s = split(sentence1, ' ');
        vector<string> t = split(sentence2, ' ');
        if (s.size() > t.size()) {
            swap(s, t);
        }
        int st = 0, e1 = s.size() - 1, e2 = t.size() - 1;
        while (st < s.size() && s[st] == t[st]) {
            ++st;
        }
        
        while (e1 >= 0 && s[e1] == t[e2]) {
            --e1, --e2;
        }
        
        return e1 < st;
    }
};