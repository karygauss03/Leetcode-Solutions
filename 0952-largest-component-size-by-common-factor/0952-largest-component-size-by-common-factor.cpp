class Solution {
public:
    int find(int a,vector<int> &p){
        if(a == p[a])return a;
        return p[a] = find(p[a],p);
    }
    void unionIt(int a,int b,vector<int> &s,vector<int> &p){
        int x = find(a,p),y = find(b,p);
        if(x != y){
            if(s[y]<s[x])swap(x,y);
            p[x] = y;
            s[y] += s[x];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n = 1e5+1,i;
        vector<int> s(n),p(n);
        for(i = 0; i < n; i++){
            s[i] = 1, p[i] = i;
        }
        for(auto &j: nums){
            for(i = 2; i <= sqrt(j); i++){
                if(j%i==0){
                    unionIt(i,j,s,p);
                    unionIt(j/i,j,s,p);
                }
            }
        }
        n = 0;
        unordered_map<int,int> mp;
        for(auto &i: nums){
            mp[find(i,p)]++;
            n = max(n,mp[find(i,p)]);
        }
        return n;
    }
};