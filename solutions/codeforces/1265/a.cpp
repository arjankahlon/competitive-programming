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

bool val(str s) {
  F0R(i, sz(s)) {
    if(s[i] == s[i - 1] || s[i] == '?') {
      return false;
    }
  }

  return true;
}

int main() {
  setIO();

  int t; cin >> t;
  rep(t) {
    str s; cin >> s;

    F0R(i, sz(s)) {
      if(s[i] == '?') {
        bool choose[3]{true,true,true};

        if(i > 0) choose[s[i - 1] - 97] = false;
        if(i < sz(s) - 1 && s[i + 1] != '?') choose[s[i + 1] - 97] = false;

        F0R(j, 3) {
          if(choose[j]) s[i] = j + 97;
        }
      }
    }

    if(val(s)) {
      cout << s;
    } else {
      cout << -1;
    }
    cout << '\n';
  }
}
