class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
        vector<int> ans,v;
        for(auto &i: arr){
            if(v.empty()||v.back()<=i){
                v.push_back(i);
                ans.push_back(v.size());
            }else{
                int x = upper_bound(v.begin(),v.end(),i) - v.begin();
                ans.push_back(x+1);
                v[x] = i;
            }
        }
        return ans;
    }
};