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
using ii= pair<int,int>;
vector<int> d;
vector<pair<pair<int,int>,int>> edges;
void solve(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		edges.pb(make_pair(make_pair(a,b),-c));
	}
	d.assign(n+1,1e18);
	d[1]=0;
	for(int i=0;i<n-1;i++){
		for(auto v: edges){
			d[v.F.S]=min(d[v.F.F]+v.S,d[v.F.S]);
		}
	}	
	int c=0;
	for(int i=0;i<m;i++){
		for(auto v: edges){
			if(d[v.F.S]>d[v.F.F]+v.S){
				c=1;
				break;
			}
		}
	}
	if(c==1){
		cout<<-1 po
	}else{
		if(d[n]!=1e18) cout<<-d[n] po
		else cout<<-1 po
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