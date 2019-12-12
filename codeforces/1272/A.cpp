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
vector<ll> v(3);
vector<ll> t ; 
ll res = INF ; 
void dfs(ll x){
    if ( x == 3 ){
        ll ans = 0 ; 
        for(ll i = 0; i < 3; i++){
            for(ll j = i + 1; j < 3; j++){
                ans += abs(t[j] - t[i]) ; 
            }
        }
        res = min(res, ans) ; 
    }
    else{
        t.push_back(v[x]);
        dfs(x + 1);
        t.pop_back();
        t.push_back(v[x] + 1);
        dfs(x + 1);
        t.pop_back();
        t.push_back(v[x] - 1);
        dfs(x + 1);
        t.pop_back();
    }
}
void solve(){
    for(ll i = 0; i < 3; i++){
        cin >> v[i] ; 
    }
    res = INF ; 
    dfs(0) ; 
    cout << res << endl;
}
int main(){
    fastio
    ll test ;
    cin >> test ;
    while(test--){
        solve() ; 
    }
    return 0; 
}
