#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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
using ll = long long ;
const int MAXN = 1e5 ;
const ll MOD = 1e9 + 7 ;
int n , m ;
vector<bool> blocked ;
ll dp[MAXN] ;
ll dfs(int x){
    if ( x > n ) return 0 ;
    if ( x == n ) return 1 ;
    if ( blocked[x] ) return 0 ;
    if ( dp[x] != -1 ) return dp[x] ;
    dp[x] = ( dfs(x+1) + dfs(x+2) ) % MOD ;
    return dp[x] ;
}


int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> m ;
    blocked.resize(n) ;
    for(int i=0;i<m;i++){
        int x ;
        cin >> x ;
        blocked[x] = true ;
    }
    cout << dfs(0) << endl;
	return 0 ;
}
