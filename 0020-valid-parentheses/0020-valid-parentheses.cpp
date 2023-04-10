class Solution {
public:
    bool isValid(string s) {
        stack<int> ss;
        if(s[0]==')' || s[0]==']' || s[0]=='}')
             return false;
        int n = s.size();
        for (int i = 0 ; i < n ; i++){
            if (s[i]=='(' || s[i]=='['  || s[i]=='{'){
                ss.push(s[i]);
            }
            else if (s[i] == ')'){
                if (ss.size() == 0 || ss.top() != '('){
                    return false;
                }
                else if (ss.top() == '('){
                    ss.pop();                        
                    continue;
                }
            }
            else if (s[i] == ']'){
                if (ss.size() == 0 || ss.top() != '['){
                    return false;
                }
                else if (ss.top() == '['){
                    ss.pop();
                    continue;
                }
            }
            else {
                if (ss.size() == 0 || ss.top() != '{'){
                    return false;
                }
                else if (ss.top() == '{'){
                    ss.pop();
                    continue;
                }
            }
        }
        if(ss.size()==0)
            return true;
        else
           return false; 
    }
};