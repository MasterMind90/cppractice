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
const int MAXN = 1e5 + 5 ; 
ll n ; 
vector<ll> v[2] ; 
ll dp[2][MAXN] ; 
ll dfs(ll x, ll row){
	if ( x >= n ){
		return 0 ; 
	}
	if ( dp[row][x] != -1 ) return dp[row][x] ; 
	ll choice1 = 0 ; 
	choice1 = v[row][x] + dfs(x+2,row) ; 
	debug() << imie(row) imie(x) imie(choice1) ;
	ll choice2 = 0 ; 
	choice2 = v[row][x] + dfs(x+1,row^1) ; 
	ll choice3 = 0 ; 
	choice3 = v[row][x] + dfs(x+2,row^1) ;
	dp[row][x] = max({choice1,choice2,choice3}) ; 
	return dp[row][x] ; 
}

int main(){
    fastio
    memset(dp,-1,sizeof dp);
    cin >> n ;
    v[0].resize(n) ;
    v[1].resize(n) ;
    for(int i=0;i<2;i++){
    	for(int j=0;j<n;j++){
    		cin >> v[i][j];
    	}
    }
    cout << max({dfs(0,1),dfs(0,0),dfs(1,1),dfs(1,0)}) << endl;

    return 0 ;
}
