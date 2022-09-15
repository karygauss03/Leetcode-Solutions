class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> ans;
        int n = changed.size();
        if (n&1) return ans;
        for (int i = 0 ; i < n - 1 ; i++){
            if (changed[i] == -1) continue;
            int l = i + 1, r = n - 1;
            int tmp = -1;
            while (l <= r){
                int mid = (l + r) /2;
                if (changed[mid] < changed[i] * 2){
                    l = mid + 1;
                }
                else if (changed[mid] > changed[i] * 2){
                    r = mid - 1;
                }
                else {
                    tmp = mid;
                    r = mid - 1;
                }
            }
            if (tmp != -1){
                ans.push_back(changed[i]);
                changed[tmp] = -1;
            }
        }
        if (ans.size() * 2 != n) return {};
        return ans;
    }
};