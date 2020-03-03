// E. Снова дерево!

#include <cstdio>
#include <iostream>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 105;

using namespace std;

int n, m, u, v, deg[N], g[N][N], used[N];
bool isTree = true;

void input() {
  speed
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    g[u][v] = g[v][u] = 1;
  }
}

void dfs(int v) {
  used[v] = 1;
  deg[v]++;
  for (int i = 1; i <= n; i++)
    if (g[v][i]) {
      g[v][i] = g[i][v] = 0;
      dfs(i);
    }
}

void solve() {
  dfs(1);
  for (int i = 1; i <= n; i++)
    if (deg[i] != 1)
      isTree = false;
}

void output() {
  cout << (isTree ? "YES" : "NO");
}

int main() {
  input();
  solve();
  output();
  return 0;
}