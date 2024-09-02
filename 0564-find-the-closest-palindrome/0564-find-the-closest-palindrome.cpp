class Solution {
public:
    string nearestPalindromic(string str) {
        int length = str.length();
        int mid = length / 2;

        if(length % 2 == 0){
            mid = mid - 1;
        }

        long way1 = makePalindrome(stol(str.substr(0, mid + 1)), length % 2);
        
        long way2 = makePalindrome(stol(str.substr(0, mid + 1)) - 1, length % 2);
        
        long way3 = makePalindrome(stol(str.substr(0, mid + 1)) + 1, length % 2);

        // Corner Cases
        long way4 = replicateNumbers(9, length);
        long way5 = replicateNumbers(1, length);
        
        vector<long> ans = {way1, way2, way3, way4, way5};
        
        long num = stol(str);
        long diff = LONG_MAX;
        long answ = LONG_MAX;
        for(int i = 0; i < 5; i++){
            if(num != ans[i] && abs(num - ans[i]) <= diff){
                if(abs(num - ans[i]) == diff){    
                    answ = min(answ, ans[i]);
                } else {
                    answ = ans[i];
                    diff = min(diff, abs(num - ans[i]));
                }
            }
        }
        return to_string(answ);
    }

    long makePalindrome(long x, bool odd){
        long num = x;

        // To Exclude the Mid
        if(odd) x = x / 10;
        
        while(x){
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    long replicateNumbers(int i, int n){
        long x = 0;
        if(i == 9){
            while(n - 1 > 0){
                x = x * 10 + 9;
                n--;
            }
        } else {
            x = 1;
            while(n > 0){
                x *= 10;
                n--;
            }
            x += 1;
        }
        return x;
    }
};