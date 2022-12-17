class Solution {
public:
    bool isNum( string s, long long &currInt ){
        currInt = 0;
        
        // If we find out any operator return false 
        if( ((s[0] == '/' || s[0] == '+' || s[0] == '-' ||
             s[0] == '*') && s.size() ==1 )) return false;
        
        // handle the negative values
        bool neg = false;
        int i=0;
        
        if( s[0] == '-' ){
            neg = true ;
            i=1;
        }
        
        // calculate the integers 
        while( i<s.size() ){
            currInt = currInt*10 + s[i++]-'0' ;
        }
        
        if( neg ) currInt = 0 - currInt;
        return true;
    }

    int evalRPN(vector<string>& tokens) {

        stack<long long> st;
        long long currInt = 0;

        for( int i=0 ; i<tokens.size() ; i++ ){
            
            // if it is an integer, push it inside ur stack 
            if( isNum(tokens[i], currInt) == true ){
                st.push( currInt );
            }
            // else compute the result and push result into stack 
            else{
                long long first = st.top(); st.pop();
                long long second = st.top(); st.pop();
                
                // Convert the operator into char, so that u can compare 
                string s = tokens[i];
                char currOpe = s[0];
                
                if( currOpe == '+' ){
                    long long tmp = first + second;
                    st.push( tmp );
                } else 
                if( currOpe == '-' ){
                    long long tmp = second - first;
                    st.push( tmp );
                }else 
                if( currOpe == '*' ){
                    long long tmp = first * second;
                    st.push( tmp );
                }else 
                if( currOpe == '/' ){
                    long long tmp = second / first;
                    st.push( tmp );
                }
            }
        }

        int ans = 0 ;
        ans = st.top();
        return ans;
    }
};