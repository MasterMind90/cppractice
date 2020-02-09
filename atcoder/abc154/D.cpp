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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
double solve(int x){
    double ans = 0 ; 
    for(int i = 1; i <= x; i++){
        ans += (double)i * (1.0/x);
    }
    return ans ; 
}
signed main(){
    fastio
    int n , k ;
    cin >> n >> k ; 
    vector<int> v(n) ; 
    for(int &x : v){
        cin >> x ;
    }
    vector<int> sum(n + 1) ;
    for(int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + v[i] ; 
    }
    int ans = 0 ; 
    int index = 0 ;
    for(int i = 1; i + k - 1 <= n; i++){
        int val = sum[i + k - 1] - sum[i - 1] ; 
        if ( val > ans ){
            ans = val ; 
            index = i - 1 ;
        }
    }
    double res = 0; 
    for(int i = 0; i < k; i++){
        debug() << imie(v[i + index]);
        res += solve(v[i + index]) ;
    }
    cout << fixed << setprecision(12) << res << endl;
    return 0; 
}