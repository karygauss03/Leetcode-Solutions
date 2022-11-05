class TrieNode{
    public:
    string word;
    TrieNode* child[26];
    
    TrieNode(){
        this->word="";
        for(int i=0;i<26;i++){
            this->child[i]=NULL;
        }
    }
};

class Solution {
public:
    
    TrieNode* root=new TrieNode();
    vector<string> ans;
    int n,m;
    
    void insert(string s){
        TrieNode* temp=root;
        for(int i=0;i<s.length();i++){
            if(temp->child[s[i]-'a']==NULL){
                temp->child[s[i]-'a']=new TrieNode();
            }
            temp=temp->child[s[i]-'a'];
            if(i==s.length()-1){
                temp->word=s;
            }
        }
    }
    
    void dfs(int x, int y, vector<vector<char>> &board, TrieNode* curr){
        if(x<0 || y<0 || x>=n || y>=m || board[x][y]=='#' || !curr){
            return;
        }
        if(curr->child[board[x][y]-'a']==NULL){
            return;
        }
        curr=curr->child[board[x][y]-'a'];
        if(curr->word!=""){
            ans.push_back(curr->word);
            curr->word="";
        }
        char c=board[x][y];
        board[x][y]='#';
        dfs(x+1,y,board,curr);
        dfs(x-1,y,board,curr);
        dfs(x,y+1,board,curr);
        dfs(x,y-1,board,curr);
        
        board[x][y]=c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto x:words){
            insert(x);
        }
        n=board.size();
        m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,board,root);
            }
        }
        return ans;
    }
};