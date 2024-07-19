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
const int N=200100;
/************** [BITWISE FUNCTIONS] **************/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }
/*************************************************/
bool is_prime(int x){
	if(x==0 || x==1){
		return 0;
	}
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int divisors(int x){
	int cnt=0;
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			if(i*i==x){
				cnt++;
			}else{
				cnt+=2;
			}
		}
	}
	return cnt;
}
/*************************************************/
vector<vector<int>> g;
int n,m;
vector<int> vis;
vector<int> parent;
bool is_cycle=false;
vector<int> cycle;
void dfs(int node, int par){
	vis[node]=1;
	parent[node]=par;
	for(auto v: g[node]){
		if(!vis[v]){
			dfs(v,node);
		}else{
			if(par!=v){
				if(is_cycle==0){
					int x=node;
					while(x!=v){
						cycle.pb(x);
						x=parent[x];
					}
					cycle.pb(x);
				}
				is_cycle=1;
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	vis.assign(n+1,0);
	parent.assign(n+1,0);
	for(int j=0;j<m;j++){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,0);
		}
	}
	if(is_cycle){
		cout<<cycle.size()+1 po
		reverse(all(cycle));
		for(auto v: cycle){
			cout<<v<<" ";
		}
		cout<<cycle[0] po
		cout po
	}else{
		cout<<"IMPOSSIBLE" po
	}
}
signed main(){
	fast
	solve();
}