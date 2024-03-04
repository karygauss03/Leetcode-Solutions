class Solution {
public:
    string maximumOddBinaryNumber(string& s) {
        int n=s.size(), n1=count(s.begin(), s.end(), '1'), n0=n-n1;
        return string(n1-1, '1')+string(n0, '0')+string(1, '1');
        
    }
};