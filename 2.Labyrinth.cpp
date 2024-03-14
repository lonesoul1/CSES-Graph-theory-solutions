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
vector<vector<char>> g;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dir[]={'L','U','R','D'};
vector<vector<int>> d;
vector<vector<ii>> par;
void bfs(ii sc){
	d.assign(n,vector<int>(m,1e9));
	par.assign(n,vector<ii>(m,{-1,-1}));
	queue<ii> q;
	d[sc.F][sc.S]=0;
	q.push(sc);
	while(!q.empty()){
		auto xx=q.front();q.pop();
		for(int i=0;i<4;i++){
			int nx=xx.F+dx[i];int ny=xx.S+dy[i];
			if(nx>=0&&ny>=0&&nx<n&&ny<m&&g[nx][ny]!='#'&&d[nx][ny]>d[xx.F][xx.S]+1){
				d[nx][ny]=d[xx.F][xx.S]+1;
				par[nx][ny]=xx;
				q.push(make_pair(nx,ny));
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	g.resize(n,vector<char> (m));
	ii st,en;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]=='A') st=make_pair(i,j);
			else if(g[i][j]=='B') en=make_pair(i,j);
		}
	}
	bfs(st);
	// for(int i=0;i<n;i++){
		// for(int j=0;j<m;j++){
			// cout<<d[i][j]<<" ";
		// }
		// cout po
	// }
	if(d[en.F][en.S]!=1e9){
		haa po
		cout<<d[en.F][en.S] po
		vector<char>ans;
		ii cur=en;
		while(cur!=make_pair(-1LL,-1LL)){
			ii xx=par[cur.F][cur.S];
			for(int i=0;i<4;i++){
				int nx=cur.F+dx[i];int ny=cur.S+dy[i];
				if(nx>=0&&ny>=0&&nx<n&&ny<m&&g[nx][ny]!='#'&&nx==xx.F&&ny==xx.S){
					ans.pb(dir[i]);
				}
			}
			cur=xx;
		}
		reverse(all(ans));
		for(auto v: ans){
			cout<<v<<"";
		}
		cout po
	}else{
		naa po
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