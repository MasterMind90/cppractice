
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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
ll n , a ;
vector<ll> v ;
const int N = 51 ;
ll dp[N][N*N][N];
ll dfs(ll x,ll cur,ll cnt){
    if ( x == n ){
        if ( cnt != 0 && (cur % cnt == 0 && cur / cnt == a) ) return 1 ;
        return 0 ;
    }
    if ( dp[x][cur][cnt] != -1 ) return dp[x][cur][cnt];
    ll ans = 0;
    ans += dfs(x + 1, cur, cnt);
    ans += dfs(x + 1, cur + v[x], cnt + 1);
    return dp[x][cur][cnt] = ans;
}

int main(){
    fastio
    memset(dp, -1, sizeof dp);
	cin >> n >> a ;
	v.resize(n);
	for(ll i = 0; i < n; i++){
        cin >> v[i] ;
	}
    cout << dfs(0,0,0) << endl;

    return 0 ;
}
