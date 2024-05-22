class Solution {
public:

	vector<vector<int>> dp;

	bool isPalindrome(int l,int r,string& s)
	{
		if(l>=r) return 1;

		if(s[l]!=s[r]) return 0;

		if(dp[l][r] !=-1) return dp[l][r];

		return dp[l][r] = isPalindrome(l+1,r-1,s);
	}

	vector<vector<string>> ans;

	void solve(int start,string s,vector<string>& partition)
	{
		if(start == s.size())
		{
			ans.push_back(partition);
			return;
		}

		for(int end=start;end<s.size();end++)
		{
			if(isPalindrome(start,end,s))
			{
				partition.push_back(s.substr(start,end-start+1));
				solve(end+1,s,partition);
				partition.pop_back();
			} 
		}

	}


	vector<vector<string>> partition(string s) {

		int n=s.size();
		dp.resize(n,vector<int>(n,-1));

		vector<string> partition;
		solve(0,s,partition);

		return ans;
	}
};