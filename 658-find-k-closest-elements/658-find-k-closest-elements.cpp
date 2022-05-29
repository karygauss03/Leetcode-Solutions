class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if (k == n) return arr;
        
        int id = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = max(0, id - 1), r = l + 1;
        while (r - l - 1 < k){
            if (l == -1){
                r++;
                continue;
            }
            if (r == n || abs(arr[l] - x) <= abs(arr[r] - x)){
                l--;
            }
            else {
                r++;
            }
        }
        vector<int> ans;
        for (int i = l + 1 ; i < r ; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};