// Problem: Game Routes
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1681
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
vector<int> indeg;
vector<int> d;
void bfs(){
	d[1]=1;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0)q.push(i);
	}
	while(!q.empty()){
		auto xx=q.front();q.pop();
		for(auto v: g[xx]){
			d[v]=(d[v]+d[xx])%MOD;
			indeg[v]--;
			if(indeg[v]==0)q.push(v);
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	indeg.resize(n+1);
	d.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		indeg[b]++;
	}
	bfs();
	cout<<d[n] po
}
signed main(){
	fast
	int _t=1;
	// cin>>_t;
	while(_t--){
		solve();
	}
}