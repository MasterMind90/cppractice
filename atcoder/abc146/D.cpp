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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    ll n ;
    cin >> n ; 
    vector<vector<ll> > g(n + 1) ; 
    vector<ll> deg(n + 1) ; 
    ll k = 0 ; 
    vector<pair<ll,ll> > v(n) ; 
    for(ll i = 0; i < n - 1; i++){
        ll a , b ;
        cin >> a >> b ; 
        v[i].first = a ;
        v[i].second = b ; 
        g[a].push_back(b) ;
        g[b].push_back(a) ; 
        deg[a]++ ; 
        deg[b]++ ; 
        k = max({k, deg[a], deg[b]}) ; 
    }
    map<pair<ll,ll>, ll> mp ; 
    vector<set<ll> > colors(n + 1) ; 
    for(ll i = 1; i <= n; i++){
        ll color = 1 ;
        for(ll &c : g[i]){
            if ( mp.find({i, c}) == mp.end() ){
                while( colors[i].find(color) != colors[i].end() ) color++ ; 
                mp[{i, c}] = color ; 
                mp[{c, i}] = color ; 
                colors[i].insert(color) ; 
                colors[c].insert(color) ; 
            }
        }
    }
    cout << k << endl;
    for(ll i = 0; i < n - 1; i++){
        cout << mp[{v[i].first, v[i].second}] << endl;
    }
    return 0; 
}