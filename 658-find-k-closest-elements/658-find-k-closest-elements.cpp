class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for (int i = 0 ; i < n ; i++){
            pq.push(make_pair(abs(x - arr[i]), arr[i]));
        }
        while (k > 0){
            pair<int,int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};