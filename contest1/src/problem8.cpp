// H. Расстояние от корня

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 105;

using namespace std;

int n, p[N], dp[N], used[N], res = 0;
vector<int> v;

void input() {
  speed
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 2; i <= n; i++)
    cin >> p[i];
}

void dfs(int v) {
  used[v] = 1;
  for (int i = 2; i <= n; i++)
    if (p[i] == v) {
      if (!used[i]) {
        dp[i] = min(dp[i], dp[v]+1);
        dfs(i);
      }
    }
}

void solve() {
  for (int i = 2; i <= n; i++)
    dp[i] = inf;
  dfs(1);
  for (int i = 1; i <= n; i++)
    res = max(res, dp[i]);
  for (int i = 1; i <= n; i++)
    if (res == dp[i])
      v.pb(i);
  sort(v.begin(), v.end());
}

void output() {
  cout << res << endl;
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
}

int main() {
  input();
  solve();
  output();
  return 0;
}