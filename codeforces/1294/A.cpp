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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    vector<ll> v(3) ;
    for(int i = 0; i < 3; i++){
        cin >> v[i] ; 
    }
    ll n ;
    cin >> n ; 
    sort(v.begin(), v.end()) ;
    ll need = v[2] - v[1] ; 
    n -= need ; 
    need = v[2] - v[0] ; 
    n -= need ; 
    if ( n < 0 ) {
        cout << "NO" << endl;
        return ;
    }
    if ( n % 3 == 0 ){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
int main(){
    fastio
    int t; 
    cin >> t ; 
    while(t--) solve() ; 
    return 0; 
}