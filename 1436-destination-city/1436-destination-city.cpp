class Solution {//Hashset
public:
  string destCity(vector<vector<string>>& paths) {                
        unordered_set<string> startingCities;
        for(auto& e: paths)  startingCities.insert(e[0]);                        
        for(auto& e: paths) 
            if(!startingCities.count(e[1])) return e[1];             
        return "";
    }
};