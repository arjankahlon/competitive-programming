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

  int m, s; cin >> m >> s;

  if(9 * m < s || !s) {
    if(!s && m == 1) {
      cout << 0 << ' ' << 0;
    } else {
      cout << -1 << ' ' << -1;
    }
    return 0;
  }

  str minRet;
  int sum = 0;
  while(sz(minRet) < m) {
    int choose = 0;
    if(!sz(minRet)) {
      choose++;
    }

    while(choose < 10) {
      if(9 * (m - sz(minRet) - 1) + choose + sum >= s) {
        break;
      }
      choose++;
    }

    sum += choose;
    minRet += to_string(choose);
  }

  str maxRet;
  sum = 0;
  while(sz(maxRet) < m) {
    int choose = 9;

    while(choose > -1) {
      if(choose + sum > s) {
        choose--;
      } else {
        break;
      }
    }

    sum += choose;
    maxRet += to_string(choose);
  }

  cout << minRet << ' ' << maxRet;
}
