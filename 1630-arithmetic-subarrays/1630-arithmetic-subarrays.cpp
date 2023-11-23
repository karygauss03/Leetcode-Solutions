class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        int m = l.size();
        vector<bool> res(m,true);
        for(size_t i =0;i<m;i++)
        {
            unordered_set<int> uset;
            vector<int> subArr(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(subArr.begin(),subArr.end());
            for(int k =1;k<subArr.size();k++)
            {
                int diff = subArr[k]-subArr[k-1];
                if(uset.empty() || uset.find(diff)==uset.end()) uset.insert(diff);
                if(uset.size()>1) {res[i]=false; break;}
            }
        }
        return move(res);
    }
};