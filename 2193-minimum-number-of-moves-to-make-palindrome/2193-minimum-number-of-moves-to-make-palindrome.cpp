class Solution {
private:
    void swap(string& s, int i, int j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0, l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l] == s[r]){
                l++; r--;
                continue;
            }
            int r_ = r;
            while(s[r_] != s[l]){
                r_--;
            }
            if(r_ == l){
                ans +=  s.size() / 2 - l;
                l++;
            }else{
                ans += r - r_;
                while(r_ < r){
                    swap(s, r_, r_ + 1);
                    r_++;
                }
                l++; r--;
            }
        }
        return ans;
    }
};