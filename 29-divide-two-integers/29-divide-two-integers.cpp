class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor == -1) return INT_MAX;
        bool sign = dividend>=0 == divisor>=0;
        long divid = labs(dividend) , divi = labs(divisor) , result = 0;
        while(divid - divi>=0){
            int cnt=0;
            while( divid - (divi<<1<<cnt)>=0)
                cnt++;
            result+=1<<cnt;
            divid -= divi<<cnt;
        }
        return sign?result:-result;
    }
};