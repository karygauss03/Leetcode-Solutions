class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> reference_map; 
    list<pair<int, int>> cache;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
    }
    
    int get(int key) {
        if(reference_map.find(key)==reference_map.end()){
            return-1;
        }
        int temp=reference_map[key]->second;
        cache.erase(reference_map[key]);
        cache.push_front({key,temp});
        reference_map[key]=cache.begin();
        return temp;
    }
    
    void put(int key, int value){
        if(reference_map.find(key)!=reference_map.end()){
            cache.erase(reference_map[key]);
            cache.push_front({key,value});
            reference_map[key]=cache.begin();
        }
        else{
            if(cache.size()<capacity){
                cache.push_front({key,value});
                reference_map[key]=cache.begin();
            }
            else{
                int evict=cache.back().first;
                reference_map.erase(evict);
                cache.pop_back();
                cache.push_front({key,value});
                reference_map[key]=cache.begin();
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */