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
const ll INF = 1e9 + 10 ; 
ll n;
vector<ll> T;
vector<ll> a ; 
void build(ll node, ll start, ll end){
    if ( start == end ){
        T[node] = a[start] ; 
    }
    else{
        ll mid = (start + end) / 2 ;
        build(2 * node, start, mid) ;
        build(2 * node + 1, mid + 1, end) ; 
        T[node] = max(T[2 * node], T[2 * node + 1]);
    }
}
ll query(ll node, ll start, ll end, ll l, ll r){
    if ( start > r || end < l ) return -INF ; 
    if ( start >= l && end <= r ){
        return T[node] ; 
    }
    else{
        ll mid = (start + end) / 2 ;
        ll p1 = query(2 * node, start, mid, l , r) ; 
        ll p2 = query(2 * node + 1, mid + 1, end, l , r) ; 
        return max(p1, p2) ;
    }
}
void solve(){
    cin >> n ; 
    T.resize(4 * n + 1) ; 
    a.resize(n) ; 
    ll nax = 0 ; 
    for(ll i = 0; i < n; i++){
        cin >> a[i] ; 
        nax = max(nax, a[i]) ; 
    }
    build(1, 0, n - 1) ; 
    ll m ; 
    cin >> m ;
    ll nax2 = 0 ; 
    vector<pair<ll,ll> > hero(m) ; 
    vector<ll> end(n + 1) ; 
    for(ll i = 0; i < m; i++){
        cin >> hero[i].first >> hero[i].second ;
        end[hero[i].second] = max(end[hero[i].second], hero[i].first) ; 
        nax2 = max(nax2, hero[i].first) ; 
    }
    if ( nax2 < nax ) {
        cout << -1 << endl ; 
        return ; 
    }
    for(ll i = n - 1; i >= 0; i--){
        end[i] = max(end[i], end[i + 1]) ; 
    }
    ll days = 0 ; 
    for(ll i = 0; i < n;){
        ll L = i , R = n - 1;
        ll ans = -1; 
        while(L <= R){
            ll mid = L + (R - L) / 2;
            ll max = query(1, 0, n - 1, i, mid);
            ll len = mid - i + 1 ;
            if ( end[len] >= max ) {
                ans = mid ; 
                L = mid + 1;
            }
            else R = mid - 1;
        }
        days++; 
        i = ans + 1;
    }
    cout << days << endl;
}
int main(){
    fastio
    ll t ;
    cin >> t ; 
    while(t--){
        solve() ; 
    }
    return 0 ; 
}