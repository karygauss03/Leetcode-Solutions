class Solution {
private:
    map<string, vector<int>> memo;
public:
    vector<int> diffWaysToCompute(string input) {
        memo.clear();
        if(memo.find(input) != memo.end()) return memo[input]; 
        vector<int> left, right, res;
        for(int i=0;i<input.size();++i){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                string inl = input.substr(0,i);
                string inr = input.substr(i+1);
                left = diffWaysToCompute(inl);
                right = diffWaysToCompute(inr);
            }
            for(int a:left){
                for(int b:right){
                    if(input[i] == '+')
                        res.push_back(a+b);
                    else if(input[i] == '-')
                        res.push_back(a-b);
                    else if(input[i] == '*')
                        res.push_back(a*b);
                }
            }
        }
        if(!res.size()) res.push_back(stoi(input));
        return memo[input] = res;
    }
};