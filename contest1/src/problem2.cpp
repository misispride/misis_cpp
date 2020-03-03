// B. Компоненты связности

#include <iostream>
#include <vector>

using namespace std;

int n{0}, m{0}, u{0}, v{0};
int comp_amount{0};

vector < vector<int> > g; // граф
vector<bool> used;
vector<int> comp;
vector<int> componenta_result;

void dfs (int v) {
  used[v] = true;
  comp.push_back(v);
  for (int & i : g[v])
    if (!used[i])
      dfs (i);
}

void find_comps() {
  for (int i=0; i<n; ++i)
    used[i] = false;
  for (int i=0; i<n; ++i)
    if (! used[i]) {
      comp.clear();
      dfs (i);

      comp_amount++;
      for (int & j : comp)
        componenta_result[j] = comp_amount;
    }
}

int main() {

  cin >> n >> m;
  g.resize(n);
  comp.resize(n);
  componenta_result.resize(n);
  used.assign(n, false);
  for (size_t i = 0; i < m; i++){
    cin >> u >> v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }

  find_comps();

  cout << comp_amount << endl;
  for (int & j : componenta_result){
    cout << j << " ";
  }

  return 0;
}