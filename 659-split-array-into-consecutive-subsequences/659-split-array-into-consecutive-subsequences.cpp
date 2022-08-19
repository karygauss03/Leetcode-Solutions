class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<vector<int>> v;
        for(int i=0; i<nums.size(); i++)
        {
            if(i==0 || v.back()[0]!=nums[i])
                v.push_back({nums[i], 1});
            else
                v.back()[1]++;
        }
        unordered_map<int, int> mp;
        for(int i=0; i<v.size(); i++)
        {
            while(v[i][1])
            {
                if(mp[v[i][0]-1]>0)
                {
                    mp[v[i][0]-1]--;
                    mp[v[i][0]]++;
                    v[i][1]--;
                }
                else 
                {
                    if(i+2<v.size() && v[i+1][0]==v[i][0]+1 &&
                       v[i+2][0]==v[i][0]+2 && v[i+1][1]>0 && v[i+2][1]>0)
                    {
                        v[i+2][1]--;
                        v[i+1][1]--;
                        v[i][1]--;
                        mp[v[i+2][0]]++;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
};