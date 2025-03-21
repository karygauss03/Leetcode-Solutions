class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> st;
        for (auto& s : supplies) st.insert(s);
        queue<int> q;
        for (int i = 0; i < recipes.size(); ++i) q.push(i);
        vector<string> ans;
        int n = -1;
        while ((int)st.size() > n) {
            n = st.size();
            int qq = q.size();
            while (qq-- > 0) {
                int i = q.front();
                q.pop();
                bool flag = true;
                for(auto& ing : ingredients[i]) {
                    if (!st.count(ing)) {
                        flag = false;
                        break;
                    }
                }

                if (!flag) q.push(i);
                else {
                    st.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                }
            }
        }
        return ans;
    }
};