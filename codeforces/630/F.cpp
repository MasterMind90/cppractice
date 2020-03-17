#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
int choose(int n, int k){
    vector<int> nomin ; 
    for(int i = 1; i <= n; i++){
        nomin.push_back(i) ;
    }
    vector<int> denom ; 
    for(int i = 1; i <= k; i++){
        denom.push_back(i) ;
    }
    for(int i = 1; i <= n - k; i++){
        denom.push_back(i) ;
    }
    for(int i = 0; i < nomin.size(); i++){
        for(int j = 0; j < denom.size(); j++){
            int g = __gcd(nomin[i], denom[j]) ; 
            nomin[i] /= g ;
            denom[j] /= g ;
        }
    }
    int ans = 1 ;
    int m = 1 ; 
    for(int i = 0; i < nomin.size(); i++){
        ans *= nomin[i] ;
    }
    for(int i = 0; i < denom.size(); i++){
        m *= denom[i] ; 
    }
    return ans / m ; 
}
signed main(){
    fastio
    int n ; 
    cin >> n ; 
    cout << choose(n, 5) + choose(n, 6) + choose(n, 7) << endl;
    return 0; 
}