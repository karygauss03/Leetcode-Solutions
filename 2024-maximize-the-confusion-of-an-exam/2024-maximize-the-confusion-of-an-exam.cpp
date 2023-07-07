class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result=0,l=answerKey.length(),left=0,right=0,tLen=0,fLen=0;
        while(right<l) {
            if(answerKey[right]=='T') {
                tLen++;
            } else {
                fLen++;
            }
            while(min(tLen,fLen)>k) {
                if(answerKey[left]=='T') {
                    tLen--;
                } else {
                    fLen--;
                }
                left++;
            }
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};