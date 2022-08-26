class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(), s.end());
        while(s[0]=='0')
            next_permutation(s.begin(), s.end());
        do{
            int temp=stoi(s);
            if(temp > 0 &&  !(temp & (temp-1)))return true;
        }while(next_permutation(s.begin(), s.end()));
        return false; 
    }
};