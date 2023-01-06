class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(),costs.end());
    int n=costs.size();
    for (int i = 0; i <n;i++)
    //we will check we can buy ice bar or not
        if (coins >= costs[i])
            coins -= costs[i];//update the coins value
        else
            return i;//we can't purchase anymore so will return ans
    return n;
       }
};