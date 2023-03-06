class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>visited(n, false);
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int currIdx = q.front();
                q.pop();
                if (currIdx == n - 1) return steps;
                if (currIdx + 1 < n && !visited[currIdx + 1])
                {
                    visited[currIdx + 1] = true;
                    q.push(currIdx + 1);
                }
                if (currIdx - 1 >= 0 && !visited[currIdx - 1])
                {
                    visited[currIdx - 1] = true;
                    q.push(currIdx - 1);
                }
                for (int newIdx : mp[arr[currIdx]]){
                    currIdx;
                    if (!visited[newIdx]) 
                    {
                        visited[newIdx] = true;
                        q.push(newIdx);
                    }
                }
                mp[arr[currIdx]].clear();
            }
            steps++;
        }
        return -1;
    }
};