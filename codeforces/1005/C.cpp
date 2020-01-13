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
int main(){
    fastio
    ll n ;
    cin >> n ; 
    vector<ll> v(n) ; 
    multiset<ll> ms ; 
    for(ll i = 0; i < n; i++){
        cin >> v[i] ; 
        ms.insert(v[i]) ; 
    }
    sort(v.begin(), v.end()) ; 
    multiset<int> good ; 
    for(ll &c : v){
        if ( good.find(c) != good.end() ) continue ; 
        bool ok = false ;
        ll val = 0 ; 
        for(ll i = 0; i < 31; i++){
            if ( (1LL << i) >= c ){
                val = (1LL << i) - c ; 
                ll cnt = ms.count(val) ; 
                if ( val == c && cnt > 1 ) {
                    ok = true ; 
                    break ; 
                }
                if ( val != c && cnt > 0 ){
                    ok = true ; 
                    break; 
                }
            }
        }
        if ( !ok ){
            ms.erase(ms.find(c));
        }
        else{
            good.insert(c) ; 
            good.insert(val) ; 
        }
    }
    cout << n - ms.size() << endl;
    return 0; 
}