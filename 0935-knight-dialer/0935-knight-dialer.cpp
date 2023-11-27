class Solution {
public:
    int knightDialer(int n) {
        int mod=1000000007;
        if(n==1)return 10;
        vector<long long int>v(10,1);
        vector<long long int>tmp(10);
        v[5]=0;
        for(int i=1;i<n;i++)
        {
            tmp[0]=(v[4]+v[6])%mod;
            tmp[1]=(v[6]+v[8])%mod;
            tmp[2]=(v[7]+v[9])%mod;
            tmp[3]=(v[4]+v[8])%mod;
            tmp[4]=(v[0]+v[3]+v[9])%mod;
            tmp[6]=(v[0]+v[1]+v[7])%mod;
            tmp[7]=(v[2]+v[6])%mod;
            tmp[8]=(v[1]+v[3])%mod;
            tmp[9]=(v[2]+v[4])%mod;
            for(int i=0;i<10;i++)
                v[i]=tmp[i];
        }
        int sum=0;
        for(int i=0;i<10;i++)
            sum=(sum+v[i])%mod;
        return sum;
    }
};