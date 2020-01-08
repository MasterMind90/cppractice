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
const ll N = 4e5 + 10 ;
const ll INF = 1e18 + 10 ;
ll n , m ; 
ll fix(ll x){
    return ( x % m + m ) % m ;
}
int main(){
    fastio
    cin >> n >> m ;
    ll need = n / m ; 
    vector<ll> v(n) ; 
    vector<vector<ll> > a(m) ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        a[v[i] % m].push_back(i) ; 
    }
    vector<ll> free ; 
    ll ans = 0 ;
    for(ll i = 0; i < m; i++){
        while( (ll) a[i].size() > need ){
            free.push_back(a[i].back());
            a[i].pop_back() ;
        }
        while( (ll) a[i].size() < need && not free.empty() ){
            ll idx = free.back() ; 
            free.pop_back() ; 
            a[i].push_back(idx) ; 
            ll inc = fix(i - v[idx]) ; 
            ans += inc ; 
            v[idx] += inc ; 
        }
    }
    for(ll i = 0; i < m; i++){
        while( (ll) a[i].size() > need ){
            free.push_back(a[i].back());
            a[i].pop_back() ;
        }
        while( (ll) a[i].size() < need && not free.empty() ){
            ll idx = free.back() ; 
            free.pop_back() ; 
            a[i].push_back(idx) ; 
            ll inc = fix(i - v[idx]) ; 
            ans += inc ; 
            v[idx] += inc ; 
        }
    }
    for(int i = 0; i < m; i++){
        assert((int)a[i].size() == need);
    }
    cout << ans << endl;
    for(ll i = 0; i < n; i++){
        cout << v[i] << ' ' ; 
    }
    cout << endl;
    return 0; 
}