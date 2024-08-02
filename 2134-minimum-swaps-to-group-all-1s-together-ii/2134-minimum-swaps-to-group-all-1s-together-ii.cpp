class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int onesCount = 0;
        for(auto it: arr){
            if(it) onesCount += 1;
        }

        int k = onesCount;
        int zeroCount = 0;
        for(int i = 0; i < k; i++){
            if(arr[i] == 0) zeroCount += 1;
        }
        int result = INT_MAX;
        result = min(result, zeroCount);
        for(int i = 0; i < n; i++){
            if(arr[(i + k)%n] == 0) zeroCount += 1;
            if(arr[i] == 0) zeroCount -= 1;
            result = min(result, zeroCount);
        }
        return result;

    }
};