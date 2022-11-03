class Solution {
public:
   int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++) mp[words[i]]++;
        int ans = 0;
        bool mid = false;
        for(auto x : mp)
        {
            if(x.first[0] != x.first[1])
            {
                string rev = x.first;
                swap(rev[0], rev[1]);
                if(mp.count(rev)) ans += 2 * (min(x.second,mp[rev]));
            }
            else
            {
                ans += 4 * (x.second/2);
                mid |= x.second%2;
            }
        }
        return mid ? ans + 2 : ans;
    }
};