class NumArray {
  public:
    vector < int > a;
  int tree[1000000];
  NumArray(vector < int > & nums) {
    memset(tree, 0, sizeof tree);
    a = nums;
    bui(0, nums.size() - 1, 1);
  }
  void bui(int st, int en, int node) {
    if (st == en) {
      tree[node] = a[st];
      return;
    }
    int mid = (st + en) / 2;
    bui(st, mid, 2 * node);
    bui(mid + 1, en, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  int qu(int l, int r, int st, int en, int node) {
    if (l > en || r < st) return 0;
    if (st >= l && en <= r) return tree[node];
    int mid = (st + en) / 2;
    return qu(l, r, st, mid, 2 * node) + qu(l, r, mid + 1, en, 2 * node + 1);
  }
  void up(int i, int st, int en, int val, int node) {
    if (st == en) {
      a[st] = val;
      tree[node] = val;
      return;
    }
    int mid = (st + en) / 2;
    if (i <= mid) up(i, st, mid, val, 2 * node);
    else up(i, mid + 1, en, val, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  void update(int index, int val) {
    up(index, 0, a.size() - 1, val, 1);
  }

  int sumRange(int left, int right) {
    return qu(left, right, 0, a.size() - 1, 1);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */