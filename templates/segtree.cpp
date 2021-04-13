struct segtree {
  int treeSz = 1;
  vector<long long> tree;

  segtree(int arrSz) {
    while(treeSz < arrSz) treeSz <<= 1;
    tree.assign(2 * treeSz, 0LL); // NOTE: Identity
  }

  segtree(int arr[], int arrSz) : segtree(arrSz) {
    build(arr, arrSz, 0, 0, treeSz);
  }

  void build(int arr[], int arrSz, int treeIdx, int loArrIdx, int hiArrIdx) {
    if(hiArrIdx - loArrIdx == 1) {
      if(loArrIdx < arrSz) {
        tree[treeIdx] = arr[loArrIdx];
      }
      return;
    }

    int midArrIdx = (loArrIdx + hiArrIdx) / 2;
    int lTreeIdx = (2 * treeIdx) + 1;
    int rTreeIdx = (2 * treeIdx) + 2;
    build(arr, arrSz, lTreeIdx, loArrIdx, midArrIdx);
    build(arr, arrSz, rTreeIdx, midArrIdx, hiArrIdx);
    tree[treeIdx] = tree[lTreeIdx] + tree[rTreeIdx]; // NOTE: Operator
  }

  void set(int arrIdx, int val) {
    set(arrIdx, val, 0, 0, treeSz);
  }

  void set(int arrIdx, int val, int treeIdx, int loArrIdx, int hiArrIdx) {
    if(hiArrIdx - loArrIdx == 1) {
      tree[treeIdx] = val;
      return;
    }

    int midArrIdx = (loArrIdx + hiArrIdx) / 2;
    int lTreeIdx = (2 * treeIdx) + 1;
    int rTreeIdx = (2 * treeIdx) + 2;
    if(arrIdx < midArrIdx) {
      set(arrIdx, val, lTreeIdx, loArrIdx, midArrIdx);
    } else {
      set(arrIdx, val, rTreeIdx, midArrIdx, hiArrIdx);
    }
    tree[treeIdx] = tree[lTreeIdx] + tree[rTreeIdx]; // NOTE: Operator
  }

  long long get(int loArrIdx, int hiArrIdx) {
    return get(loArrIdx, hiArrIdx, 0, 0, treeSz);
  }

  long long get(int loArrIdx, int hiArrIdx, int treeIdx, int currLoArrIdx, int currHiArrIdx) {
    if(hiArrIdx <= currLoArrIdx || currHiArrIdx <= loArrIdx) return 0; // NOTE: Identity
    if(loArrIdx <= currLoArrIdx && currHiArrIdx <= hiArrIdx) return tree[treeIdx];

    int currMidArrIdx = (currLoArrIdx + currHiArrIdx) / 2;
    int lTreeIdx = (2 * treeIdx) + 1;
    int rTreeIdx = (2 * treeIdx) + 2;
    return get(loArrIdx, hiArrIdx, lTreeIdx, currLoArrIdx, currMidArrIdx) + get(loArrIdx, hiArrIdx, rTreeIdx, currMidArrIdx, currHiArrIdx); // NOTE: Operator
  }
};
