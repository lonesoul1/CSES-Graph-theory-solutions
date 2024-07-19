#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define haa cout<<"YES"
#define naa cout<<"NO"
#define po <<"\n";
#define pb emplace_back
#define pof pop_front
#define pob pop_back 
#define all(a) a.begin(), a.end()
#define MOD 1000000007	
#define F first
#define S second
const int N = 200010;

/*************************************************/
#define MAXN 202020

int n, m;
vector<vector<int>>adj;
vector<bool>visited;
vector<int>bridges;

void DFS (int node) {
  visited[node] = true;
  for (auto child : adj[node]) {
    if (visited[child] == false) {
      DFS(child);
    }
  }
}

signed main() {
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1,0);
    for (int i = 0 ; i < m; i++) {
      int node1, node2;
      cin >> node1 >> node2;
      adj[node1].push_back(node2);
      adj[node2].push_back(node1);
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        bridges.push_back(i);
        DFS(i);
      }
    }
    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++) {
      cout << bridges[i] << " " << bridges[i + 1] << endl;
    }
    return 0;
}