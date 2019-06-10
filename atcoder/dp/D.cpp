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
typedef long long ll;
const ll MAXW = 1e5 + 10 ;
ll n , W ;
ll w[110] , v[110] ;
ll dp[110][MAXW] ;
ll dfs(ll x,ll currWeight){
    if ( x == n ) {
        return 0 ;
    }
    if ( dp[x][currWeight] ) return dp[x][currWeight] ;
    ll choice1 = 0 ;
    ll choice2 = 0 ;
    if ( currWeight < w[x] ){
        choice1 = dfs(x+1,currWeight) ;
    }
    else{
        choice1 = dfs(x+1,currWeight) ;
        choice2 = v[x] + dfs(x+1,currWeight-w[x]) ;
    }
    dp[x][currWeight] = max(choice1,choice2) ;
    return dp[x][currWeight] ;
}

int main(){
    cin >> n >> W ;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i] ;
    }
    cout << dfs(0,W) << endl;
    return 0 ;
}
