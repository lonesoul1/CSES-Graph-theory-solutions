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
void solve(){
	int n,m,q;cin>>n>>m>>q;
	vector<vector<int>> d(n+1,vector<int>(n+1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==j) d[i][j]=0;
			else d[i][j]=1e18;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);
		d[b][a]=min(d[a][b],c);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		if(d[a][b]!=1e18){
			cout<<d[a][b] po
		}else{
			cout<<-1 po
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