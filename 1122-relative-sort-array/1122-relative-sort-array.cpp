class Solution {
public:
    unordered_map<int, int> mp;
    int cmp(int a) {
        return mp.count(a) ? mp[a] : mp.size();
    }
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for(int i = 0; i < arr2.size(); ++i) {
            mp[arr2[i]] = i;
        }
        
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            return cmp(a) == cmp(b) ? a < b : cmp(a) < cmp(b);
        });
        
        return arr1;
    }
};