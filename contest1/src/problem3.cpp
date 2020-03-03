// C. Пошаговый обход графа

#include <iostream>
#include <vector>

using namespace std;

vector<bool> a;
vector<vector<int>> b;

void DFS(int v) {
  cout << v + 1 << ' ';
  a[v] = true;
  for (int i = 0; i < b[v].size(); i++) {
    int c = b[v][i];
    if (!a[c]) {
      DFS(c);
      cout << v + 1 << ' ';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, s, i, x, y;
  cin >> n >> m >> s;
  s--;
  a.assign(n, false);
  b.resize(n);
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    b[x - 1].push_back(y - 1);
    b[y - 1].push_back(x - 1);
  }
  cout << 2 * n - 1 << endl;
  DFS(s);

  return 0;
}