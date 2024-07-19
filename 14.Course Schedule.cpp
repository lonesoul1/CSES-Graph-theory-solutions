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
int n,m;
vector<vector<int>> g;
vector<int> col;
vector<int> par;
// vector<int> ans;
vector<int> topo;
int is_cycle=0;
void dfs(int node,int p){
	if(is_cycle==1) return;
	par[node]=p;
	col[node]=2;
	for(auto v: g[node]){
		if(col[v]==1){
			dfs(v,node);
		}else if(col[v]==2){
			is_cycle=1;
		}
	}
	col[node]=3;
	topo.pb(node);
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	col.resize(n+1,1);
	par.resize(n+1,-1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].pb(b);
	}
	for(int i=1;i<=n;i++){
		if(col[i]==1){
			dfs(i,0);
		}
	}
	if(is_cycle==1){
		cout<<"IMPOSSIBLE" po
	}else{
		reverse(all(topo));
		for(int i=0;i<topo.size();i++){
			cout<<topo[i]<<" ";
		}
	}
}
signed main(){
	fast
	int _t=1;
	// cin>>_t;
	while(_t--){
		solve();
	}
}