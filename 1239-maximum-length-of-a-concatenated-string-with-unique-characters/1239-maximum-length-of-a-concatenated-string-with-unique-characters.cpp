class Solution {
public:
    int maxLength(vector<string>& A) {
        vector<bitset<26> > dp={ bitset<26>() };
        int res = 0;
        for (auto& s : A){
            bitset<26> a;
            for(char c: s){
                a.set(c - 'a');
            }
            int n = a.count();
            if(n < s.size()){
                continue;
            }
            for (int i = dp.size() - 1; i >= 0; --i){
                 bitset<26> c = dp[i];
                if ((c & a).any())
                    continue;
                dp.push_back(c | a);
                res = max(res, (int)c.count() + n);
            }
        }
        return res;
    }
};