class Solution {
public:
    int maxScore(string s) {
        int n1=s.size();
        int y=0;
        for (int i=0; i<n1;i++){
            if(s[i]=='1') y++;
        }
        int temp=0;
        int result=0;
        for(int i=0;i<n1-1;i++){
            if(s[i]=='0'){
                temp++;
            }
            else{
                y--;
            }
            result=max(result,(temp+y));
        }
        return result;
        
    }
};