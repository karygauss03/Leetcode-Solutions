class Solution {
public:
    int candy(vector<int>& arr) {
        int cand[100001] = {0};
        int n = arr.size();
        for(int i = 1; i < n; i++) 
            if(arr[i] > arr[i-1]) cand[i] = cand[i-1] + 1;
        for(int i = n-2; i>= 0; i--) 
            if(arr[i] > arr[i+1]) cand[i] = max(cand[i], cand[i+1] + 1);
        int sum = n;
        for(int i = 0; i < n; i++) sum += cand[i];
        return sum;
    }
};