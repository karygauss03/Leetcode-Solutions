class Solution {
public:
    int giveCount(string &it){
        int cnt=1;
        for(int j=0;j<it.size()-1;j++){
            if(it[j]==it[j+1]){
                cnt++;
            }else break;
        }
        return cnt;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>q,w;
        for(auto &it:queries){
            sort(it.begin(),it.end());
            int cnt=giveCount(it);
            q.push_back(cnt);
        }
       
        for(auto &it:words){
            sort(it.begin(),it.end());
            int cnt=giveCount(it);
            w.push_back(cnt);
        }
        sort(w.begin(),w.end());
        vector<int>ans;
        int n=words.size();
        for(auto &it:q){
            auto it1=upper_bound(w.begin(),w.end(),it)-w.begin();
            ans.push_back(n-it1);
        }
        return ans;
    }
};