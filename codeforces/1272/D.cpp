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
int main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<ll> v(n + 2) ; 
    v[0] = 0 ; 
    for(int i = 1; i <= n; i++){
        cin >> v[i] ; 
    }
    v[n + 1] = INF ; 
    vector<int> leftInc(n + 2, 1) ; 
    leftInc[0] = 0 ;
    leftInc[n + 1] = 0 ;
    for(int i = 1; i <= n; i++){
        if ( v[i] > v[i - 1] ) leftInc[i] = leftInc[i - 1] + 1;
    }
    vector<int> rightDec(n + 2, 1) ; 
    rightDec[0] = 0 ;
    rightDec[n + 1] = 0 ;
    for(int i = n; i >= 1; i--){
        if ( v[i] < v[i + 1] ) rightDec[i] = rightDec[i + 1] + 1;
    }
    debug() << imie(leftInc) ; 
    debug() << imie(rightDec) ; 
    int ans = *max_element(leftInc.begin(), leftInc.end()) ;
    for(int i = 2; i < n; i++){
        int tmp = 0 ; 
        if ( v[i + 1] > v[i - 1] ) tmp = rightDec[i + 1] + leftInc[i - 1] ; 
        ans = max(ans, tmp) ; 
    }
    cout << ans << endl;
    return 0; 
}