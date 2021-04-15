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

  int n, h, a, b, k; cin >> n >> h >> a >> b >> k;
  F0R(i, k) {
    int ta, fa, tb, fb; cin >> ta >> fa >> tb >> fb;
    int ret = INF;
    if(ta == tb) {
      ret = abs(fa - fb);
    } else if(fa > b) {
      ret = abs(fa - b) + abs(ta - tb) + abs(fb - b);
    } else if(fa < a) {
      ret = abs(fa - a) + abs(ta - tb) + abs(fb - a);
    } else {
      ret = abs(ta - tb) + abs(fa - fb);
    }
    cout << ret << '\n';
  }
}
