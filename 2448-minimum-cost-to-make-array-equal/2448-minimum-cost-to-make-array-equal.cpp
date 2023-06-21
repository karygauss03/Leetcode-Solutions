class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        long long ans = LLONG_MAX;
        vector<long long> pref; 
        vector<pair<long, long>> p; 
        for(int i = 0; i < cost.size(); i++)
         {
            p.push_back({nums[i], cost[i]});
        }
        
        sort(p.begin(), p.end()); 
        pref.push_back(0); 
        for(int i = 0; i < p.size(); i++)
         {
            pref.push_back(pref[i] + p[i].second);
        }
        long long left = 0, right = 0;
        for(int i = 0; i < nums.size(); i++)
         {
            if(i == 0)
             {
                left = 0;
                for(int j = 1; j < cost.size(); j++)
                 {
                    right += (long long)(p[j].first - p[0].first) * (long long)p[j].second;
                }
                if(ans > right + left)
                 {
                    ans = left + right;
                }
                continue;
            }
            long long elevation = p[i].first - p[i - 1].first;
            right -= elevation * (long long)(p[i].second);
            right -= elevation * (pref[pref.size() - 1] - pref[i + 1]);
            left += elevation * (pref[i] - pref[0]);
            if(ans > right + left)
             {
                ans = left + right;
            }
        }
        return ans;
    }
};
