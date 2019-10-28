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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll INF = 1e18 + 10 ;
int main(){
    fastio 
    ll n , k ; 
    cin >> n >> k ; 
    vector<pair<ll, ll> > v(n) ; 
    set<ll> s ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i].second >> v[i].first ; 
        s.insert(v[i].second) ; 
    }
    sort(v.rbegin(), v.rend()) ;
    ll types = (ll) s.size() ; 
    ll L = 1, R = min(k,types) ; 
    auto solve = [&](ll mid){
        if ( mid > k ) return 0LL ; 
        set<ll> ss ; 
        ll c = mid ; 
        ll ans = 0 ;
        vector<bool> mark(n) ; 
        for(ll i = 0; i < n && c; i++){
            if ( ss.find(v[i].second) == ss.end() ){
                ans += v[i].first ; 
                ss.insert(v[i].second) ; 
                mark[i] = true ; 
                c--;
            }
        }
        c = k - mid ; 
        for(ll i = 0; i < n; i++){
            if ( !mark[i] && c ){
                ans += v[i].first ; 
                c--;
            }
        }
        return ans + mid * mid; 
    };
    ll ans = 0 ;
    while(L <= R){
        ll mid = L + (R - L) / 2 ;
        ll a = solve(mid) ;
        ll b = solve(mid + 1) ;
        if ( mid + 1 > min(k,types) ) {
            b = solve(mid - 1) ;
        }
        ans = max(a, b);
        if ( a < b ){
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << ans << endl;
    return 0 ;
}