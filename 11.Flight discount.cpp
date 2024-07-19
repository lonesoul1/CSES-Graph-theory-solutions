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
using ii=pair<int,int>;
vector<vector<ii>> g;
vector<int> d;
vector<int> v;
vector<int> nr;
void dijkstra(int sc){
	d.assign(n+1,1e18);
	v.assign(n+1,0);
	nr.resize(n+1,0);
	priority_queue<ii> pq;
	d[sc]=0;
	pq.push({-0,sc});
	while(!pq.empty()){
		auto xx=pq.top();pq.pop();
		for(auto [u,w]: g[xx.S]){
			if(d[w]>d[xx.S]+w){
				d[u]=d[xx.S]+w;
				nr[u]=nr[xx.S];
				pq.push({-d[u],u});
			}else if(d[u]==d[xx.S]+w){
				nr[u]=(nr[u]+nr[xx.S])%MOD;
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		g[a].pb(make_pair(b,c));
		// g[b].pb(make_pair(a,c));
	}
	dijkstra(1);
	
}
signed main(){
	fast
	int _t=1;
	// cin>>_t;
	while(_t--){
		solve();
	}
}