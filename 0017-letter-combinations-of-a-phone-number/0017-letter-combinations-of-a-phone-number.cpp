class Solution {
public:
    unordered_map <char,string> m;
    vector <string> ans;
    void dfs(int i,string gen,string digits)
    {
        if(i==digits.size())
        {
            ans.push_back(gen);
            return;
        }
        for(char c:m[digits[i]])
        {
            dfs(i+1,gen+c,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return ans;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        dfs(0,"",digits);
        return ans;
    }
};