class Solution
{
public:
    int dfs(vector<int> &v, vector<vector<int>> &b, int i)
    {
        v[i] = 1;
        int x = b[i][0], y = b[i][1];
        int r = b[i][2];
        int j = 0;
        int ans = 1;
        for (int j = 0; j < b.size(); j++)
        {
            long long g = abs(x - b[j][0]);
            g *= g;
            long long gg = abs(y - b[j][1]);
            gg *= gg;
            double dis = sqrt(g + gg);
            if (dis <= (r) && !v[j])
            {
                ans += dfs(v, b, j);
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>> &b)
    {
        int n = b.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> v(n, 0);
            if (!v[i])
            {
                ans = max(ans, dfs(v, b, i));
            }
        }
        return ans;
    }
};