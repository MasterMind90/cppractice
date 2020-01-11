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
ll lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}
int main(){
    fastio
    ll n ; 
    cin >> n ; 
    vector<ll> div ; 
    for(ll i = 1; i * i <= n; i++){
        if ( n % i == 0 ){
            div.push_back(i) ; 
            if ( n / i != i ) {
                div.push_back(n / i) ; 
            }
        }
    }
    sort(div.begin(), div.end());
    ll m = (ll) div.size() ;
    debug() << imie(div) ; 
    debug() << imie(m) ;
    ll nax = INF ; 
    pair<ll,ll> ans ;
    for(ll i = 0; i < m; i++){
        if ( lcm(div[i], n / div[i]) == n && max(div[i], n / div[i]) < nax){
            ans = make_pair(div[i], n / div[i]);
            nax = max(div[i], n / div[i]);
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
    return 0; 
}