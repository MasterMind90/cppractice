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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    ll n ;
    cin >> n ; 
    string s ; 
    cin >> s ; 
    vector<ll> v(n) ; 
    map<ll,ll> mp ; 
    vector<ll> sum(n + 1) ; 
    for(ll i = 0; i < n; i++){
        if ( s[i] == 'L' ) v[i] = -1; 
        else if ( s[i] == 'R' ) v[i] = 1 ;
        else if ( s[i] == 'D' ) v[i] = 1e6 ; 
        else if ( s[i] == 'U' ) v[i] = -1e6 ; 
    }
    debug() << imie(v) ;
    for(int i = 1; i <= n; i++){
        sum[i] += sum[i - 1] + v[i - 1] ; 
    }
    debug() << imie(sum)  ;
    mp[0] = 0 ; 
    ll x , y ; 
    ll ans = INF ;
    for(int i = 1; i <= n; i++){
        if ( i == 1 ){
            mp[sum[i]] = i ; 
            continue ; 
        }
        auto it = mp.find(sum[i]) ; 
        if ( it != mp.end() ){
            if ( i - it->second < ans ){
                ans = i - it->second ; 
                x = it->second , y = i ; 
            }
        }
        mp[sum[i]] = i ; 
    }
    if ( ans == INF ){
        cout << -1 << endl;
    }
    else cout << x + 1 << ' ' << y << endl;
}
int main(){
    fastio
    ll t ;
    cin >> t ;
    while(t--) solve() ; 
    return 0 ; 
}