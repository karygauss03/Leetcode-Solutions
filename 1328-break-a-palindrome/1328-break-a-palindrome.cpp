class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        int idx=0;
        bool fixed=false;
        while(idx<palindrome.size() && !fixed){
            if(palindrome[idx] != 'a' && (palindrome.size() != (2*idx + 1))){
                palindrome[idx]='a';
                fixed=true;
                break;
            }
            idx++;
        }
        if(!fixed)
            palindrome[palindrome.size()-1]+=1;
        return palindrome;
    }
};