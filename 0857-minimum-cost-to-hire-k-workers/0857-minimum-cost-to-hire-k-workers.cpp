class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int N = quality.size();
        vector<pair<double, int>>vec; // ratio, quality
        for(int i = 0; i < N; i++) {
            vec.push_back(make_pair(wage[i] * 1.0 / quality[i], quality[i])); 
        }
				// sort in ascending order
        sort(vec.begin(), vec.end(), [](auto& a, auto& b){
            return a.first < b.first;
        });
        int quality_cnt = 0;
        priority_queue<int> q; // max-min heap
        for(int i = 0; i < K; i++) {
            quality_cnt += vec[i].second;
            q.push(vec[i].second);
        }
        double ans = quality_cnt * vec[K - 1].first;
        for(int i = K; i < N; i++) {
            q.push(vec[i].second);
            quality_cnt += vec[i].second;
            quality_cnt -= q.top();
            q.pop();
            ans = min(ans, quality_cnt * vec[i].first);
        }
        return ans;
    }
};