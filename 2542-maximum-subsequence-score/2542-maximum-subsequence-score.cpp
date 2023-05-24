class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>vec;
        for(int i=0; i<n; i++)
            vec.push_back({nums2[i],nums1[i]});//store nums2[i] and nums1[i] as pair to sort according to nums2[i]
        
        sort(vec.begin(),vec.end());//will give sorted array in ascending order basred on the nums2[i]
        
        long long res=0,currSum=0;
        priority_queue<int, vector<int>, greater<int>>pq;//we need priority queue (min heap) so that we can remove the minimum element from the selected element as we are bound to take only k elements 
        
        for(int i=n-1; i>n-1-k; i--)
        {
            pq.push(vec[i].second);//push nums1[i] in the min heap
            currSum+=vec[i].second;//store the sum of all those numbers
        }
        
        res=max(res,currSum*vec[n-k].first);//and the score will be sum*(minimum of selected index of nums2[i])
        
        for(int i=n-1-k; i>=0; i--)//now we will run the loop over all the starting form the last selected index to get the naximum score(if any)
        {
            int mini=pq.top();
            pq.pop();
            currSum-=mini;//we will remove the smallest number of all the taken numbers till now and will add the current number
            
            currSum+=vec[i].second;
            pq.push(vec[i].second);
            
            res=max(res,currSum*vec[i].first);
        }
        
        return res;
    }
};