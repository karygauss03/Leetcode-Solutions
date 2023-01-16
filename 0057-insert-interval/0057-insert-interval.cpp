class Solution {
public:
     vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        vector<vector<int>> ans;
        if(in.size()<1) {
            ans.push_back(ni);
            return ans;
        }
        int n=in.size();
        int i=0, j=n-1;
        while(i<n && ni[0]>in[i][0]){
            ans.push_back(in[i]);
            i++;
        }
        while(j>=0 && ni[1]<in[j][1]){
            ans.push_back(in[j]);
            j--;
        }
        ans.push_back(ni);
        sort(ans.begin(),ans.end());
        
        vector<vector<int>> res;
        res.push_back(ans[0]);
        j = 0;
        i = 1;
        while(i<ans.size()){
            if(res[j][1] >= ans[i][0]){
                res[j][1] = max(res[j][1], ans[i][1]);
            }
            else{
                res.push_back(ans[i]);
                ++j;
            }
            ++i;
        }
        return res;
     }
};