class Solution {
public:
    long long minimumReplacement(vector<int>& num) {
        int n = num.size(), rightValue = num[n - 1];
        long long ans = 0 , breakValue;
        
        if(n == 1) {
            return 0;
        }
        
        for(int i = n - 2 ; i >= 0 ;  --i){
            if(rightValue >= num[i]) {
                rightValue = num[i];
            }
            else{
                breakValue = ((num[i] - 1) / rightValue) + 1;
                rightValue = num[i] / breakValue;
                ans += (breakValue - 1);
            }       
        }
        return ans;    
    }
};