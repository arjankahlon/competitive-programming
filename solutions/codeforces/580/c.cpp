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

  int n, m; cin >> n >> m;
  bool bad[n]{};
  vector<vi> adj;
  adj.assign(n, vi());
  F0R(i, n) {
    int ai; cin >> ai;
    if(ai) {
      bad[i] = true;
    }
  }
  rep(n - 1) {
    int ai, bi; cin >> ai >> bi; ai--; bi--;
    adj[ai].pb(bi);
    adj[bi].pb(ai);
  }

  deque<pi> dq;
  bool vis[n]{};
  int ret = 0;
  dq.pb(mp(0, 0));
  vis[0] = true;
  while(sz(dq)) {
    pi c = dq.back();
    dq.pop_back();

    if(bad[c.f]) {
      c.s++;
    } else {
      c.s = 0;
    }

    if(c.s <= m) {
      if(sz(adj[c.f]) == 1 && c.f != 0) {
        ret++;
      }

      each(nx, adj[c.f]) {
        if(!vis[nx]) {
          dq.pb(mp(nx, c.s));
          vis[nx] = true;
        }
      }
    }
  }
  cout << ret;
}
