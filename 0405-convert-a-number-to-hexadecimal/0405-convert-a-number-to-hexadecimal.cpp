class Solution {
public:
    string toHex(int num) {    
        if (num == 0) {
            return "0";
        }
        int HEXA = 16;
        string S = "0123456789abcdef";
        unsigned int n = num;
        string res;
        
        while (n > 0) {
            res = S[n % HEXA] + res;
            n /= HEXA;
        }
        return res;
    }
};