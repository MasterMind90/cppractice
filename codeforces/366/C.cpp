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
const int INF = 1e9 + 10;
const int N = 1e5 ; 
int n , k ;
vector<int> a , b;
int dp[110][2 * N];
int fix(int x){
	return x + N ; 
}
int dfs(int x,int curDiff){
	if ( x == n ){
		if ( curDiff == 0 ) return 0 ; 
		return -INF ; 
	}
	if ( dp[x][fix(curDiff)] != -1 ) return dp[x][fix(curDiff)] ; 
	int choice1 = dfs(x+1,curDiff) ; 
	int choice2 = a[x] + dfs(x+1,curDiff + (a[x] - b[x]) ) ; 
	return dp[x][fix(curDiff)] = max(choice1,choice2) ;
}
int main(){
    fastio
    memset(dp,-1,sizeof dp) ;
    cin >> n >> k ; 
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++){
    	cin >> a[i] ;
    }
    for(int i=0;i<n;i++){
    	cin >> b[i] ;
    	b[i] = b[i] * k ; 
    }
    int ans = dfs(0,0) ; 
    if ( ans <= 0 ) {
    	cout << -1 << endl;
    }
    else cout << ans << endl;
    return 0 ;
}
