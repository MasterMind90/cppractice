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
int main(){
    fastio
    ll n , m ; 
    cin >> n >> m ; 
    vector<ll> v(n) ; 
    set<int> s ;
    set<int> tree ;
    map<int,int> dist ; 
    queue<ll> q ;
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        dist[v[i]] = 0 ; 
        s.insert(v[i]) ; 
        tree.insert(v[i]) ; 
        q.push(v[i]) ;
    }
    ll ans = 0 ; 
    while(not q.empty()){
        if ( m <= 0 ) break ; 
        ll f = q.front() ; q.pop() ; 
        if ( s.find(f - 1) == s.end() && m > 0 ){
            dist[f - 1] = dist[f] + 1 ;
            ans += dist[f - 1] ; 
            s.insert(f - 1) ; 
            q.push(f - 1) ; 
            m--;
        }
        if ( s.find(f + 1) == s.end() && m > 0 ){
            dist[f + 1] = dist[f] + 1 ;
            ans += dist[f + 1] ;
            s.insert(f + 1) ; 
            q.push(f + 1) ;
            m--;
        }
    }
    cout << ans << endl;
    for(ll c : s){
        if ( tree.find(c) == tree.end() ){
            cout << c << ' ' ;
        }
    }
    return 0; 
}