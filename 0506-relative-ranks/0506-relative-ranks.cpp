class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans (n);
        priority_queue<pair<int, int>> pq;
        for (int i = 0 ; i < n ; i++){
            pq.push(make_pair(score[i], i));
        }
        int x = 0;
        while (!pq.empty()){
            auto p = pq.top();
            pq.pop();
            x++;
            if (x == 1){
                ans[p.second] = "Gold Medal";
                continue;
            }
            if (x == 2){
                ans[p.second] = "Silver Medal";
                continue;
            }
            if (x == 3){
                ans[p.second] = "Bronze Medal";
                continue;
            }
            ans[p.second] = to_string(x);
        }
        return ans;
    }
};