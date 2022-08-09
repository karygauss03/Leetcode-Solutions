class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        vector<long long> dp(A.size(),1);
        sort(A.begin(),A.end());
        const int mod=1000000000+7;
        unordered_map<int,int> ms;
        for(int i=0;i<A.size();i++)
        {
            ms[A[i]]=i;
            for(int j=i-1;j>=0;j--) 
            {
                if(A[i]%A[j]==0)
                {
                    int t=A[i]/A[j];
                    if(ms.count(t)) dp[i]+=(dp[j]*dp[ms[t]])%mod;
                }
            }
        }
        
        long long ans=0;
        ans=accumulate(dp.begin(),dp.end(),0LL);
        return ans%mod;;
    }
};