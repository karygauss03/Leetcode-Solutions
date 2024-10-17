class Solution {
public:
    int maximumSwap(int num)
    {
        multiset<int, greater<int> > s;
        vector<int> v;
        while(num > 0)
        {
            int temp = num % 10;
            v.push_back(temp);
            s.insert(temp);
            num /= 10;
            
        }
        reverse(v.begin(), v.end());
        int i = 0;
        int digittoswap = -1;
        int digitswapped = -1;
        for(multiset<int, greater<int> >::iterator it = s.begin(); it != s.end(); it++)
        {
            if(v[i] != *it)
            {
                digittoswap = v[i];
                v[i] = *it;
                digitswapped = *it;
                break;
            }
            i++;
        }
        if(digittoswap != -1 && digitswapped != -1)
        {
            
            for(int j=v.size()-1;j>=0; j--)
            {
                if(v[j] == digitswapped)
                {
                    v[j] = digittoswap;
                    break;
                }
            }
        }
        //Make number
        int res = 0;
        for(int i=0; i<v.size(); i++)
        {
            res = res*10 + v[i];
        }
        return res;
    }

};