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
vector<int> vis;
vector<int> dis;
vector<int> par;
void bfs(int sc){
	vis.assign(n+1,0);
	dis.assign(n+1,1e9);
	par.assign(n+1,-1);
	queue<int> q;
	dis[sc]=1;
	q.push(sc);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto v: g[node]){
			if(dis[node]+1<dis[v]){
				dis[v]=dis[node]+1;
				q.push(v);
				par[v]=node;
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(1);
	if(dis[n]==1e9){
		cout<<"IMPOSSIBLE" po
	}else{
		cout<<dis[n] po
		// cout<<n<<" ";
		int cur=n;
		vector<int> ans;
		ans.pb(n);
		while(cur!=-1){
			cur=par[cur];
			ans.pb(cur);
		}
		reverse(all(ans));
		for(int i=1;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout po
	}
}
signed main(){
	fast
	// int _t=1;
	// cin>>_t;
	// while(_t--){
		solve();
	// }
}