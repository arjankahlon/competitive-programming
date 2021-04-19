struct segtree {
  int n;
  vector<int> t;

  segtree(int pn) {
    n = pn;
    t.assign(2 * n, 0);
    for(int i = n - 1; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
  }

  void set(int i, int v) {
    for(t[i += n] = v; i > 1; i >>= 1) t[i >> 1] = t[i] + t[i ^ 1];
  }

  int get(int l, int r) {
    int ret = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) ret += t[l++];
      if(r & 1) ret += t[--r];
    }
    return ret;
  }
};
