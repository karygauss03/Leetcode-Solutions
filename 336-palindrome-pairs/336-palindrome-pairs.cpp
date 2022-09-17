typedef struct TrieNode{
    vector<int> in;
    TrieNode* child[26];
    TrieNode(){
	    memset(child,0, sizeof(child));
        //child.resize(256,NULL);
    }
}TrieNode;

class Solution {
public:
	bool isPal(const string &w,int s,int e){
		while(s<=e){ 
			if(w[s] != w[e])
				return false;
			s++;
			e--;
		}
		return true;
	}

	void insert(TrieNode* node,const string &w, int i){
		for(char c: w){
            c = c-'a';
			if(node->child[c] == NULL){
				node->child[c] = new TrieNode();
			}
			node = node->child[c];
		}
		node->in.push_back( i);
	}

	vector<int> search(TrieNode* node,const string &w, int start, int end){
		//vector<vector<int>> ans(w.size()+1); 
		for(int i = end; i >= start; i--){
            char c = w[i];
			node = node->child[c-'a'];
            if(node == NULL){
                return {};
            }
		}
		return node->in;
	}
	vector<vector<int>> palindromePairs(vector<string>& arr) {
		int n = arr.size();
		TrieNode* trie = new TrieNode();
        //TrieNode* revTrie = new TrieNode();
		int in =0;
		for(string w: arr){
            insert(trie,w,in);
			in++;
		}
		set<vector<int>> ans;
        in = 0;
		for(string w: arr){
            if(w.size())
            for(int i = 0; i <= w.size(); i++){
                if(isPal(w,i,w.size()-1)){// w as first
                    auto all = search(trie,w,0,i-1);
                    for(auto in2: all){
                        if(in != in2)
                        ans.insert({in,in2});
                    }
                }
                if(isPal(w,0,i-1)){//w as second
                    auto all = search(trie,w,i, w.size()-1);
                    for(auto in2: all){
                        if(in!= in2)
                        ans.insert({in2,in});
                    }
                }
            }
            in++;
		}
		return vector<vector<int>>(ans.begin(),ans.end());
	}

};