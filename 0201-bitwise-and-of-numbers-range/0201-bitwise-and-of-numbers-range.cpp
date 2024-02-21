class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int x = right;
        while(x>left){
            x = x&(x-1);
        }
        return x;
    }
};