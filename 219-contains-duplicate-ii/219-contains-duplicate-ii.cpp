class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int,int> ma;
        ma[a[0]] = 0;
        
        for (int i = 1 ; i < n ; i++){
            if (ma.find(a[i]) != ma.end()){
                if (abs(i - ma[a[i]]) <= k){
                    return true;
                }
                else {
                    ma[a[i]] = i;
                }
            }
            else {
                ma[a[i]] = i;
            }
        }
        return false;
    }
};