class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int a = 0;

        for (int i = 0; i < n; i++)
            if (s[i] == 'a')
                a++;

        int b = 0;
        int ret = INT_MAX;
        for (int i = 0; i < n; i++){
            ret = min(ret, a+b);
            if (s[i] == 'b')
                b++;
            else if (s[i] == 'a')
                a--;
        }
        ret = min(ret, a+b);
        return ret;
    }
};