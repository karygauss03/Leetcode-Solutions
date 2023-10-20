/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

int next() {
    int result = nodes.top().getInteger();
    nodes.pop();
    return result;
}

bool hasNext() {
    while(!nodes.empty()) {
        NestedInteger curr = nodes.top();
        if(curr.isInteger()) {
            return true;
        }
        
        nodes.pop();
        vector<NestedInteger>& adjs = curr.getList();
        int size = adjs.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(adjs[i]);
        }
    }
    
    return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */