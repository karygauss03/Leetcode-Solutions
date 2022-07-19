class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1;i<=numRows;i++){
            vector<int> temp;
            if(i==1){
                temp.push_back(1);
            } else if(i==2){
                temp = {1,1};
            } else {
                int n = ans[i-1-1].size();
                temp.push_back(1);
                for(int j = 1;j<n;j++){
                    temp.push_back(ans[i-1-1][j-1] + ans[i-1-1][j]);
                }
                temp.push_back(1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};