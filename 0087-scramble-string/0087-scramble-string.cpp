class Solution {
public:
    int dp[30][30][31];
    int solve(string& a, string& b, int l1, int l2, int len){
        int& ret = dp[l1][l2][len];
        if (~ret) return ret;
        ret = 0;
        bool sameString = 1;
        for (int i = 0; i < len && sameString; i++){
            sameString &= (a[i+l1] == b[i+l2]);
        }
        ret = sameString;
		// if the two substrings are equal or only remain substring of size = 1 
        if (len == 1 || sameString) return sameString;
        for (int cut = 1; !ret && cut < len; cut++){
            ret = (solve(a, b, l1, l2, cut) && 
					solve(a, b, l1 + cut, l2 + cut, len - cut));
			// if ret == 1, we won't going to try this ... reason for ret || 
            ret = (ret || (solve(a, b, l1+cut, l2, len - cut) && 
							solve(a, b, l1, l2 + len - cut, cut)));
        }
        return ret;
    }
    bool isScramble(string s1, string s2) {
        memset(dp, -1 ,sizeof dp);
        return solve(s1, s2, 0, 0, s1.size());
    }
};