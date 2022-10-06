class TimeMap {
public:
    map<string, map<int, string>> ma;
    TimeMap() {
        ;
    }
    
    void set(string key, string value, int timestamp) {
        ma[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        for(auto it=ma[key].end();it!=ma[key].begin();){
            if ((--it)->first >timestamp )continue;
            else return it->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */