class Solution {
private: 
    int n;
    int ans;
    string vowels = "aeiou"; //00000
    int mask;
    map<int, int> ma;
public:
    int findTheLongestSubstring(string s) {   
        n = s.size(), ans = -1;
        mask = 0;
        ma[0] = -1;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < 5 ; j++){
                if (s[i] == vowels[j]){
                    //there is a vowel which is the j-th one
                    mask ^= (1<<j);
                    break;
                }
            }
            if (ma.find(mask) == ma.end()){
                ma[mask] = i;
            }
            ans = max(ans, i - ma[mask]);
        }
        return ans;
    }
};