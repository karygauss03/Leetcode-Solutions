class Solution {
    static bool cmp(int a,int b){
        int resulta = __builtin_popcount(a);
        int resultb = __builtin_popcount(b);
        if(resultb == resulta){
            return a < b;
        }
        return resultb > resulta;    
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};