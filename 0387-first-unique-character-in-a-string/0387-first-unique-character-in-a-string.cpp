class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
    
        for(int i =0;i<s.length();i++){

            if(mp.find(s[i]) != mp.end()){
                mp[s[i]] = -1;
            }else{
                mp[s[i]] = i;
            }
        }

        int mini = 1e9;
        for(auto itr = mp.begin();itr != mp.end();itr++){
            if(itr->second < mini and itr->second != -1){
                mini = itr->second;
            }
        }
        return mini != 1e9 ?  mini: -1;
    }
};