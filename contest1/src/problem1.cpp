// A. Связность

#include <iostream>
#include <vector>

using namespace std;

vector < vector<int> > g; // граф
vector<bool> used;
void dfs (int v) {
  used[v] = true;
  for (int & i : g[v])
    if (!used[i])
      dfs (i);
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  used.assign(n, false);
  int u, v;
  for (size_t i = 0; i < m; i++){
    cin >> u >> v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }

  dfs(u-1);

  for (bool f : used){
    if (!f){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}