class Solution {
public:
    string decodeAtIndex(string S, int K) {
        size_t decoded_size = 0;
        string res = "";
        
        for (auto a : S) {
            if (isdigit(a))
                decoded_size *= a - '0';
            else
                decoded_size++;
        }
        
        for (int i = S.size()-1; i >= 0; i--) {
            K %= decoded_size;
            
            if (!isdigit(S[i]) && K == 0)
                return res + S[i];
            
            if (isdigit(S[i]))
                decoded_size /= S[i]-'0';
            else
                decoded_size--;
        }
        
        return res;
    }
};