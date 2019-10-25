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
const ll INF = 1e9 + 10 ;
const ll N = 1e5 + 10 ;
ll p[N] ; 
ll r[N] ;
vector<ll> cnt(N);
ll Find(ll x){
    if ( p[x] == x ) return x; 
    p[x] = Find(p[x]) ; 
    return p[x] ; 
}
void unite(ll x,ll y){
    ll Px = Find(x) ; 
    ll Py = Find(y) ; 
    if ( Px == Py ) return ; 
    if ( r[Px] == r[Py] ){
        cnt[Px] += cnt[Py];
        p[Py] = Px ;
        r[Px] += 1 ;
    }
    else if ( r[Px] < r[Py] ){
        cnt[Py] += cnt[Px] ; 
        p[Px] = Py;
    }
    else {
        cnt[Px] += cnt[Py];
        p[Py] = Px ; 
    }
}
int main(){
    fastio 
    for(ll i = 0; i < N; i++){
        p[i] = i ; 
        cnt[i] = 1;
    }
    ll n , m ;
    cin >> n >> m ;
    vector<ll> ans(m) ; 
    ans[m - 1] = n * (n - 1) / 2 ;
    vector<pair<ll, ll> > v(m) ; 
    for(ll i = 0; i < m; i++){
        cin >> v[i].first >> v[i].second ; 
    }
    for(ll i = m - 1; i > 0; i--){
        ll Px = Find(v[i].first) , Py = Find(v[i].second);
        debug() << imie(Px) imie(Py) ;
        if ( Px == Py ) {
            ans[i - 1] = ans[i] ;
        }
        else{
            ans[i - 1] = ans[i] - (cnt[Px] * cnt[Py]);
            unite(Px, Py) ; 
        }
    }
    for(ll i = 0; i < m; i++){
        cout << ans[i] << endl;
    }
    return 0 ;
}