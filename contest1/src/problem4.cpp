// D. Волновой обход графа

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 105;

using namespace std;

int n, m, v, g[N][N], used[N], dp[N];
vector<pii > res;

void input() {
  speed
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> m >> v;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = 1;
  }
}

void bfs(int s) {
  used[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (g[v][i] && !used[i]) {
        dp[i] = min(dp[i], dp[v] + 1);
        used[i] = 1;
        q.push(i);
      }
    }
  }
}

void solve() {
  for (int i = 1; i <= n; i++)
    dp[i] = inf;
  dp[v] = 0;
  bfs(v);
  for (int i = 1; i <= n; i++)
    if (used[i])
      res.pb(mp(dp[i], i));
  sort(res.begin(), res.end());
}

void output() {
  cout << res.size() << endl;
  for (auto & re : res)
    cout << re.S << ' ';
}

int main() {
  input();
  solve();
  output();
  return 0;
}