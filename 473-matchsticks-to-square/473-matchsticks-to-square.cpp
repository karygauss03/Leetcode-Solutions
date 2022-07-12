class Solution {
public:
    int dp[100005][5];
    int solve(vector<int>& M,int cur,int mask,int target)
    {
        int N = M.size();
        if(cur > 4)return 0;
        if(cur == 4)
        {
            return (mask == ((1 << N) - 1));
        }
        if(dp[mask][cur] != -1)return dp[mask][cur];
        int can = 0;
        for(int i=1;i < (1 << N);i++){
            if(mask & i)continue;
            int s = 0;
            for(int j=0;j<N;j++)
            {
                if(i & (1 << j))
                {
                    s += M[j];
                }
            }
            if(s == target)
            {
                can = can || solve(M,cur + 1,i | mask,target);
            }
            if(can)break;
        }

        return dp[mask][cur] = can;
    }
    bool makesquare(vector<int>& matchsticks) {
        memset(dp,-1,sizeof dp);
        long long sum = 0;
        for(int x:matchsticks){
            sum += x;
        }
        if(sum % 4 != 0)return 0;

        return  solve(matchsticks,0,0,sum / 4);
    }
};