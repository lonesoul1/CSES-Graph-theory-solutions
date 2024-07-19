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
using ii=pair<int,int>;
int n,m;
vector<vector<char>> g;
queue<ii> per;
queue<ii> mon;
vector<vector<int>> dism;
vector<vector<int>> disp;
vector<vector<ii>> parp;
vector<vector<ii>> parm;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int dir[]={'L','U','R','D'};
void solve(){
	cin>>n>>m;
	g.resize(n+1,vector<char> (m));
	dism.assign(n+1,vector<int> (m,1e9));
	disp.assign(n+1,vector<int>(m,1e9));
	parp.assign(n+1,vector<ii>(m,{-1,-1}));
	parm.assign(n+1,vector<ii>(m,{-1,-1}));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char x;cin>>x;
			g[i][j]=x;
			if(x=='A'){
				per.push({i,j});
				disp[i][j]=0;
			}else if(x=='M'){
				mon.push({i,j});
				dism[i][j]=0;
			}
		}
	}
	while(!per.empty()){
		auto xx=per.front();per.pop();
		for(int i=0;i<4;i++){
			int nx=xx.F+dx[i];int ny=xx.S+dy[i];
			if(nx>=0&&ny>=0&&nx<n&&ny<m&&g[nx][ny]!='#'&&disp[nx][ny]>disp[xx.F][xx.S]+1){
				disp[nx][ny]=disp[xx.F][xx.S]+1;
				per.push({nx,ny});
				parp[nx][ny]={xx.F,xx.S};
			}
		}
	}
	
	while(!mon.empty()){
		auto xx=mon.front();mon.pop();
		for(int i=0;i<4;i++){
			int nx=xx.F+dx[i];int ny=xx.S+dy[i];
			if(nx>=0&&ny>=0&&nx<n&&ny<m&&g[nx][ny]!='#'&&dism[nx][ny]>dism[xx.F][xx.S]+1){
				dism[nx][ny]=dism[xx.F][xx.S]+1;
				mon.push({nx,ny});
				parm[nx][ny]={xx.F,xx.S};
			}
		}
	}
	int f=0;
	ii an;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0 || j==0 || i==n-1 || j==m-1){
				if(disp[i][j]<dism[i][j]){
					f=1;
					an={i,j};
					break;
				}
			}
		}
	}
	// for(int i=0;i<n;i++){
		// for(int j=0;j<m;j++){
			// cout<<disp[i][j]<<" ";
		// }
		// cout po
	// }
	// cout po
	// for(int i=0;i<n;i++){
		// for(int j=0;j<m;j++){
			// cout<<dism[i][j]<<" ";
		// }
		// cout po
	// }
	if(f==1){
		haa po
		cout<<disp[an.F][an.S] po
		vector<char>ans;
		ii cur=an;
		while(cur!=make_pair(-1LL,-1LL)){
			ii xx=parp[cur.F][cur.S];
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