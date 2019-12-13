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
const ll N = 2e6 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    ll n ; 
    cin >> n ; 
    vector<ll> v(n + 1) ; 
    vector<vector<ll> > g(n + 1) ; 
    for(ll i = 1; i <= n; i++){
        cin >> v[i] ; 
        if ( i + v[i] <= n ) g[i + v[i]].push_back(i) ; 
        if ( i - v[i] >= 1 ) g[i - v[i]].push_back(i) ; 
    }
    vector<ll> dist1(n + 1, INF) ; 
    queue<ll> q ;
    for(ll i = 1; i <= n; i++) {
        if ( v[i] % 2 == 0 ) {
            dist1[i] = 0 ; 
            q.push(i) ;
        }
    }
    while(not q.empty()){
        ll f = q.front() ; q.pop() ; 
        for(ll &c : g[f]){
            if ( dist1[c] > dist1[f] + 1 ){
                dist1[c] = dist1[f] + 1 ;
                q.push(c) ; 
            }
        }
    }
    vector<ll> dist2(n + 1, INF) ; 
    for(ll i = 1; i <= n; i++){
        if ( v[i] & 1 ){
            dist2[i] = 0 ; 
            q.push(i);
        }
    }
    while(not q.empty()){
        ll f = q.front() ; q.pop() ; 
        for(ll &c : g[f]){
            if ( dist2[c] > dist2[f] + 1 ){
                dist2[c] = dist2[f] + 1 ;
                q.push(c) ; 
            }
        }
    }
    debug() << imie(dist1) ; 
    debug() << imie(dist2) ; 
    for(ll i = 1; i <= n; i++){
        if ( dist1[i] == INF || dist2[i] == INF ) cout << -1 << ' '; 
        else cout << dist1[i] + dist2[i] << ' ' ; 
    }
    cout << endl;
    return 0; 
}