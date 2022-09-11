class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1e9 + 7;
        vector<pair<int,int>> v;
        for (int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>, greater<int>> q;
        long long sumSpeed = 0 , ans = 0;
        for (auto [eff,speed] : v){
            q.push(speed);
            sumSpeed += speed;
            if (q.size()> k) {
                sumSpeed -= q.top();
                q.pop();
            }
            ans = max(ans,sumSpeed*eff);
        }
        return ans%mod;
    }
    
};