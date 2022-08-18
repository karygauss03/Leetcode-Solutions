class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        priority_queue<int> Q;
        int ans = 0, rem = 0;
        for (int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        for (auto f : freq){
            Q.push(f.second);
        }
        while (rem < arr.size()/2){
            rem += Q.top();
            Q.pop();
            ans++;
        }
        return ans;
    }
};