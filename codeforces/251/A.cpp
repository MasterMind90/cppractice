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
const ll INF = 1e18 ; 
ll C(ll n, ll k){
    ll res = 1; 
    // Since C(n, k) = C(n, n-k) 
    if ( k > n - k ) 
        k = n - k; 
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (ll i = 0; i < k; ++i) {
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
} 
int main(){
    fastio
    ll n , d ; 
    cin >> n >> d ; 
    vector<ll> v(n) ; 
    for(ll &x : v){
        cin >> x ; 
    }
    v.push_back(INF) ; 
    ll ans = 0 ; 
    for(int i=0;i<n;i++){
        int index = upper_bound(v.begin(),v.end(),v[i]+d) - v.begin() ; 
        index-- ; 
        if ( index - i >= 2 ){
            ans += C(index-i,2) ; 
        }
    }
    cout << ans << endl;
    return 0 ;
}
