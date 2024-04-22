class Solution {
public:
    int openLock(vector<string>& deadends, string tar) {
        if(tar=="0000")
            return 0;
        int ans=0;
        unordered_set<int> dead;
        for(auto& s:deadends)
            dead.insert(stoi(s));
        if(dead.count(0))
            return -1;
        bool visited[10000];
        memset(visited,false,sizeof(visited));
        int target=stoi(tar);
        queue<int> q;
        q.push(0);visited[0]=true;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string s=get(q.front());q.pop();
                int sn;
                for(int i=0;i<4;++i){
                    s[i]=((s[i]+1-'0')%10)+'0';
                    sn=stoi(s);
                    if(target==sn)
                        return ans+1;
                    if(!dead.count(sn) && !visited[sn])
                        q.push(sn),visited[sn]=true;
                    
                    s[i]=((s[i]+8-'0')%10)+'0';
                    sn=stoi(s);
                    if(target==sn)
                        return ans+1;
                    if(!dead.count(sn) && !visited[sn])
                        q.push(sn),visited[sn]=true;
                    
                    s[i]=((s[i]+1-'0')%10)+'0';
                }
            }
            ans++;
        }
        return -1;
    }
private:
    string get(int n) {
        string ans=to_string(n);
        ans=string(4-ans.length(),'0')+ans;
        return ans;
    }
};