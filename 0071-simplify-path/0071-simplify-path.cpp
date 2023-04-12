class Solution {
public:
	string simplifyPath(string s) {
		vector<string> p;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '/') {
				string temp;
				int l = i + 1;
				while(l < s.size() && s[l] != '/') {
					temp.push_back(s[l]);
					l++;
				}
				if(temp.empty() || temp == ".")
					continue;
				if(temp == "..") {
					if(!p.empty())  p.pop_back();
				}
				else 
					p.push_back(temp);
			}
		}
		string ans;
		for(auto& str : p) 
			ans += "/" + str;
		return (ans.empty() == true) ? "/" : ans; 
	}
};