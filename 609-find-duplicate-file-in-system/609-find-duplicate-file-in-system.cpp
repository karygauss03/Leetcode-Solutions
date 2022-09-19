class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
    // total paths
    int n = paths.size();
    
    // to store string
    vector<vector<string>>ans;
    
    // to store path which store same data 
    unordered_map<string,vector<string>>mp;
    
    
    for(int i=0;i<n;i++){
        int len = paths[i].size();
        string path = "";
        string curr = paths[i];
        int j = 0;
        while(curr[j] != ' '){
            path += curr[j];
            j++;
        }
        j++;
        while(j<len){
            string temp = path;
            temp+='/';
            while(curr[j]!='('){
                temp += curr[j];
                j++;
            }
            string data = "";
            while(curr[j]!=')'){
                data += curr[j];
                j++;
            }
            mp[data].push_back(temp);
            j+=2;
        }
    }
    
    for(auto it:mp){
        vector<string>st;
        if(it.second.size()==1){
            continue;
        }
        for(auto itt : it.second){
            st.push_back(itt);
        }
        ans.push_back(st);
    }
    return ans;
}
};