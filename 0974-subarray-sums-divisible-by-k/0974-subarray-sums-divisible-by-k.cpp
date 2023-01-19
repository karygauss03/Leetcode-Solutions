class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
	    vector<int> pref(k, 0);
	    int sum = 0;
	    pref[0]++;
	    for(int i = 0 ; i < n ; i++){
	        sum += arr[i];
	        int rem = (sum % k + k) % k;
	        ans += pref[rem];
	        pref[rem]++;
	    }
	    return ans;
    }
};