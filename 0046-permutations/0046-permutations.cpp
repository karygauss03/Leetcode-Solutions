class Solution {
public:
    vector<vector<int>>ans;
    void help(int mask,vector<int>&v,vector<int>&temp){
        if(mask==0){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(mask & (1<<i)){
                temp.push_back(v[i]);
                help(mask ^ (1<<i), v,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        vector<int>temp;
        help((1<<v.size())-1,v,temp);
        return ans;
    }
};
