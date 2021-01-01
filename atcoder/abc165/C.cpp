#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
~debug() { cerr << '\n'; }
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int n , m , q;
vector<vector<int> > all ; 
vector<int> curSequence ; 
void recur(int x, int last){
	if ( x == n ){
		all.push_back(curSequence) ;
		return ;
	}
	for(int i = last; i <= m; i++){
		curSequence.push_back(i) ;
		recur(x + 1, i) ;
		curSequence.pop_back() ;
	}
}
signed main(){
    fastio
    cin >> n >> m >> q ;
    recur(0, 1) ;
    vector<array<int, 4>> v(q) ;
    for(int i = 0; i < q; i++){
    	for(int j = 0; j < 4; j++){
    		cin >> v[i][j] ;
    	}
    	v[i][0]--;
    	v[i][1]--;
    }
    int ans = 0 ;
    for(auto &seq : all){
    	int sum = 0 ;
    	for(int i = 0; i < q; i++){
    		int a = v[i][0] ;
    		int b = v[i][1] ;
    		int c = v[i][2] ;
    		int d = v[i][3] ;
    		if ( seq[b] - seq[a] == c ) sum += d ;
    	}
    	ans = max(ans, sum) ;
    }
    cout << ans << endl;
    return 0; 
}
