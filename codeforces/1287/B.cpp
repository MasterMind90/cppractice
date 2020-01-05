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
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    ll n , k ;
    cin >> n >> k ; 
    vector<string> v(n) ;
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    map<ll,map<string,ll> > mp ;
    map<string,ll> cnt ; 
    for(ll i = 0; i < n; i++){
        cnt[v[n - i - 1]]++;
        mp[n - i - 1] = cnt ; 
    }
    char ar[] = {'E','S','T'};
    ll ans = 0 ;
    for(ll i = 0; i + 3 <= n; i++){
        for(ll j = i + 1; j < n; j++){
            string s = "" ; 
            for(ll c = 0; c < k; c++){
                if ( v[i][c] == v[j][c] ){
                    s += v[i][c] ; 
                }
                else{
                    for(char ch : ar){
                        if ( ch == v[i][c] ) continue ;
                        if ( ch == v[j][c] ) continue ;
                        s += ch ; 
                        break;
                    }
                }
            }
            debug() << imie(s) ;
            ans += mp[j + 1][s];
        }
    }
    cout << ans << endl;
    return 0; 
}