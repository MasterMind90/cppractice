

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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;
int main(){
    fastio
    ll a , b ;
    cin >> a >> b ;
    vector<ll> common ;
    for(ll i = 1; i * i <= min(a, b); i++){
        if ( a % i == 0 ){
            if ( b % i == 0 ){
                common.push_back(i) ;
            }
            if ( a / i != i ){
                if ( b % (a / i) == 0 ) common.push_back(a / i) ;
            }
        }
    }
    sort(common.begin(),common.end());
    int n = (int) common.size() ;
    vector<bool> mark(n) ;
    for(int i = 1; i < n; i++){
        if ( !mark[i] )
            for(int j = i + 1; j < n; j++){
                if ( common[j] % common[i] == 0 ) mark[j] = true ;
            }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        if ( !mark[i] ) ans++ ;
    }
    cout << ans << endl;
    return 0 ;
}
