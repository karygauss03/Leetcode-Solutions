class Solution {
public:
    int addDigits(int num) {
        if ( num == 0 ) return 0;
        return num%9 == 0 ? 9 : num%9 ;
    }
};