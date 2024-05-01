class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> tokenWithExpirationTime;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokenWithExpirationTime[tokenId] = currentTime + this->timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if ((tokenWithExpirationTime.find(tokenId) != tokenWithExpirationTime.end()) && (tokenWithExpirationTime[tokenId] > currentTime)) {
            tokenWithExpirationTime[tokenId] = currentTime + this->timeToLive;   
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        
        for (auto &mp : tokenWithExpirationTime) {
            if (mp.second > currentTime) {
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */