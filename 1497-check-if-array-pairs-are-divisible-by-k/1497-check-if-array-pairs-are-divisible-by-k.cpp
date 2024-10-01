class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        int num_pair =0;
        multiset<int>st;
        for(auto &i: arr){
            i = ((i % k) + k) % k;  
        }
        for(auto i:arr){
            if(i==0){

              if(st.find(i)!=st.end()){
                st.erase(st.find(i));
                num_pair++;
              }
              else{
                st.insert(i);
              }
            }
            else{
              int comp = k-i;
              if(st.find(comp)!=st.end()){
                st.erase(st.find(comp));
                num_pair++;
              }
              else{
                st.insert(i);
              }
            }

        }
        return (num_pair==n/2);
    }
};