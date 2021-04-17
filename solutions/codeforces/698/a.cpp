#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& a: x)

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9+7;
const int INF = 1e9;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int main() {
  setIO();

  int n; cin >> n;

  int prev[3]{};
  FOR(i, 1, n + 1) {
    int curr[3]{};
    int ai; cin >> ai;
    F0R(j, 3) {
      int ret = INF;

      bool val = false;
      F0R(k, 2) {
        if((j & (1 << k)) && (ai & (1 << k))) {
          val = true;
        }
      }

      F0R(k, 3) {
        if(k == j || !val) {
          ret = min(ret, prev[k] + 1);
        } else {
          ret = min(ret, prev[k]);
        }
      }

      curr[j] = ret;
    }

    F0R(i, 3) {
      prev[i] = curr[i];
    }
  }

  int ret = INF;
  F0R(i, 3) {
    ret = min(ret, prev[i]);
  }
  cout << ret;
}
