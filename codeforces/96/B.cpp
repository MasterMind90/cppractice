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
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(0) ;
using ll = long long ;
const ll INF = 1e10 + 10 ;
const ll N = 1e10 ;
vector<ll> ans ;
void dfs(ll x){
    if ( x > N ) return ;
    ans.push_back(x) ;
    dfs(x * 10 + 4) ;
    dfs(x * 10 + 7) ;
}
int main(){
    fastio
    dfs(0) ;
    ans.erase(ans.begin()) ;
    ll n ;
    cin >> n ;
    vector<ll> v ;
    for(ll &x : ans){
        ll c = x ;
        ll a = 0 , b = 0 ;
        while(c != 0){
            if ( c % 10 == 7 ) b++ ;
            else a++ ;
            c /= 10 ;
        }
        if ( a == b ) v.push_back(x) ;
    }
    sort(v.begin(), v.end()) ;
    ll index = lower_bound(v.begin(), v.end(), n) - v.begin() ;
    cout << v[index] << endl;
    return 0 ;
}
