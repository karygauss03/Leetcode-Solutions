class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int curr = 0; //show current score
        int ans = 0; //store the final score
        sort(tokens.begin(), tokens.end()); //sort the array
        int i = 0; //integer to traverse array from beginning
        int j = tokens.size() - 1; //integer to traverse array from end
        while(i <= j){ //Check till i is less than or equal to j
            if(tokens[i] <= power){ //If value of token at i less than power
                curr++; //Increment of curr
                if(ans < curr){ //Check if ans is less than curr
                    ans = curr; //Update ans equal to curr
                }
                power = power - tokens[i]; //Reduce value at token i from power
                i++; //Increase the value of i by 1
            }
            else if(ans > 0){ //Else if ans is greater than 0
                power = power + tokens[j]; //Add value of last token to power from sorted array
                curr--; //Decrement the curr by 1
                j--; //Decrement the value of j by 1
            }
            else{
                break; //Finally break the loop
            }
        }
        return ans;
    }
};