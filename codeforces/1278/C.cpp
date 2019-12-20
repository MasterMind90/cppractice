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
    ll n ; 
    cin >> n ; 
    vector<ll> left(n) , right(n) ;
    ll cur = 0 ; 
    map<ll,ll> mpp ; 
    for(ll i = 0; i < n; i++){
        cin >> left[i] ;
        if ( left[i] == 1 ){
            cur++;
        }
        else cur--;
        left[i] = cur ; 
        mpp[cur] = i ; 
    }
    for(ll i = 0; i < n; i++){
        cin >> right[i] ;
    }
    reverse(right.begin(), right.end()) ; 
    map<ll,ll> mp ; 
    cur = 0 ; 
    for(ll i = 0; i < n; i++){
        if ( right[i] == 1 ) cur++ ; 
        else cur-- ; 
        right[i] = cur ; 
        mp[cur] = i ; 
    }
    ll ans = 0 ; 
    for(ll i = 0; i < n; i++){
        if ( left[i] == 0 ) ans = max(ans, i + 1) ; 
        if ( mp.find(-left[i]) != mp.end() ) ans = max(ans, i + 1 + mp.find(-left[i])->second + 1 );
    }
    for(ll i = 0; i < n; i++){
        if ( right[i] == 0 ) ans = max(ans, i + 1) ; 
        if ( mpp.find(-right[i]) != mpp.end() ) ans = max(ans, i + 1 + mpp.find(-right[i])->second + 1 );
    }
    debug() << imie(ans) ; 
    cout << 2 * n - ans << endl;
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