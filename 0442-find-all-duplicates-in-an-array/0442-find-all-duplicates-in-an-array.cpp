class Solution {
public:
    vector<int> findDuplicates(vector<int>& n)
    {
        vector<int> duplicates;
        
        for(int i=0;i<n.size();i++)
        { 
            int indexOfElem = abs(n[i]) - 1;
            
            n[indexOfElem] = - n[indexOfElem];
            if(n[indexOfElem]>0)
                duplicates.push_back(indexOfElem+1);
            
        }
        return duplicates;
    }
};