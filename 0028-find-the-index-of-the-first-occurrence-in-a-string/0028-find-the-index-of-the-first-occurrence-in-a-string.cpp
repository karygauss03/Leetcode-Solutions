class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int x = 0;
        for(int i = 0; i < n; i++)
        {
            if(haystack[i] == needle[x]) x++;
            else 
            {
                i = i - x;
                x = 0;
            }
            if(x == m) return i - x + 1;
        }
        return -1;
    }
};