class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int zeros=0;
        for(auto ch:s)
            if(ch=='0')
                zeros++;
        
        int count1=0,count0=0;
        int ans=zeros;
       for(auto ch:s)
       {
           if(ch=='0')
               count0++;
           else
               count1++;
           ans=min(ans,count1+zeros-count0);
       }
        return ans;
            
    }
};