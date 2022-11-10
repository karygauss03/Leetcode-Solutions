class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int size=s.size(),cnt=1;
        vector<int>pre(size,0),suf(size,0);
        pre[0]=1;
        for(int i=1;i<size;i++){
            if(s[i]<=s[i-1])
                cnt++;
            else
                cnt=1;
             pre[i]=cnt;
        }
        suf[size-1]=1;cnt=1;
        for(int i=size-2;i>=0;i--){
            if(s[i]<=s[i+1])
                cnt++;
            else
                cnt=1;
            suf[i]=cnt; 
        }
        vector<int>ans;
        for(int i=0;i<size;i++)
            if(pre[i]-1>=time && suf[i]-1>=time)
                ans.push_back(i);
        return ans;
    }
};