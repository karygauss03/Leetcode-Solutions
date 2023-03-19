class BrowserHistory {
public:
    int ele;
    vector<string> vc;
    BrowserHistory(string homepage) {
        vc.push_back(homepage);
        ele  =0;
    }
    
    void visit(string url) {
        int l = vc.size()-1;
        while(l>ele){
            vc.pop_back();
            l--;
        }
        ele++;
        vc.push_back(url);
    }
    
    string back(int steps) {
        ele-=steps;
        if(ele<0) ele=0;
        return vc[ele];
    }
    
    string forward(int steps) {
        ele +=steps;
        if(ele>=vc.size()) ele = vc.size()-1;
        return vc[ele];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */