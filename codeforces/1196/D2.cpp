#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
void solve(){
	int n , k ; 
	string s ; 
	cin >> n >> k ; 
	cin >> s ; 
	string rgb = "RGB" ; 
	int ans = 1e9 ; 
	for(int i=0;i<3;i++){
		string t = s ; 
		int cur = i ; 
		for(int j=0;j<n;j++){
			t[j] = rgb[cur%3] ; 
			cur++ ; 
		}
		vector<int> sum(n+1) ; 
		for(int j=0;j<n;j++){
			if ( s[j] != t[j] ){
				sum[j+1] = 1 ; 
			}
		}
		for(int j=1;j<=n;j++){
			sum[j] += sum[j-1] ; 
		}
		debug() << imie(sum) ; 
		for(int j=0;j+k<=n;j++){
			ans = min(ans,sum[j+k]-sum[j]);
		}
	}
	cout << ans << endl;
}
int main(){
	fastio
	int t ;
	cin >> t ;
	while(t--){
		solve() ;
	}
	return 0 ;
}
