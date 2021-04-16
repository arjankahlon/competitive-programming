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

  int t; cin >> t;
  rep(t) {
    int n; cin >> n;
    str s; cin >> s;

    int m = 0, t = 0;

    int pfix[n + 2]{};
    int sfix[n + 2]{};
    F0R(i, n) {
      pfix[i + 1] = pfix[i];
      if(s[i] == 'T') {
        t++;
        pfix[i + 1]++;
      } else {
        m++;
      }
    }

    R0F(i, n) {
      sfix[i + 1] = sfix[i + 2];
      if(s[i] == 'T') {
        sfix[i + 1]++;
      }
    }

    bool val = true;
    int curr = 0;
    F0R(i, n) {
      if(s[i] == 'M') {
        curr++;

        if(pfix[i + 1] < curr) {
          val = false;
        }

        if(sfix[i + 1] < (m - curr) + 1) {
          val = false;
        }
      }
    }

    if(t != 2 * m) {
      val = false;
    }
    cout << (val ? "YES" : "NO") << '\n';
  }
}
