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
const int MAXN = 1e5 + 10 ; 
int n ;
vector<int> A(MAXN), B(MAXN), C(MAXN) ; 
int dp[MAXN][4] ; 
int dfs(int idx,int last){
	if ( idx == n ){
		return 0 ; 
	}
	int &res = dp[idx][last] ; 
	if ( res != -1 ) return res ; 
	int ans = 0 ; 
	if ( last != 1 ){
		ans = max(ans,A[idx] + dfs(idx+1,1) );  
	}
	if ( last != 2 ){
		ans = max(ans,B[idx] + dfs(idx+1,2) );  
	}
	if ( last != 3 ){
		ans = max(ans,C[idx] + dfs(idx+1,3) );  
	}
	return res = ans ; 
}
int main(){
    fastio
    memset(dp,-1,sizeof dp) ; 
    cin >> n ; 
    for(int i=0;i<n;i++){
    	cin >> A[i] >> B[i] >> C[i] ; 
    }
    cout << dfs(0,0) << endl;
    return 0 ;
}
