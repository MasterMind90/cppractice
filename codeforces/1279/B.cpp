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
const ll N = 2e5 + 10 ;
const ll INF = 1e9 + 10 ;
void solve(){
    ll n , m ;
    cin >> n >> m ; 
    vector<ll> v(n) ; 
    vector<ll> sum(n + 1) ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        sum[i + 1] = sum[i] + v[i] ; 
    }
    if ( sum[n] <= m ) {
        cout << 0 << endl;
        return ; 
    }
    ll ans = 0 ; 
    ll index = 0 ; 
    int cnt = 0 ;
    for(ll i = 1; i <= n; i++){
        if ( sum[i] <= m ){
            cnt = i ; 
        }
        ll left = sum[i - 1] ; 
        ll L = i + 1, R = n ; 
        while(L <= R){
            ll mid = L + (R - L) / 2 ;
            if ( (sum[mid] - sum[i]) + left <= m ){
                if ( mid - 1 > ans ){
                    index = i ; 
                    ans = mid - 1;
                }
                L = mid + 1 ;
            }
            else R = mid - 1;
        }
    }
    if ( cnt > ans ){
        cout << 0 << endl;
    }
    else cout << index << endl;
}
int main(){
    fastio
    ll t ;
    cin >> t ;
    while(t--){
        solve() ; 
    }
    return 0; 
}