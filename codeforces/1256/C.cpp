#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define int long long
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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 1 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio;
    int n , m , d ;
    cin >> n >> m >> d ;
    vector<int> p(m) ;
    int sum = 0 ; 
    for(int i = 0; i < m; i++){
        cin >> p[i] ;
        sum += p[i] ;
    }
    vector<int> ans(n) ;
    int start = n - 1 ;
    for(int i = m - 1; i >= 0; i--){
        int val = p[i] ;
        while(val > 0){
            ans[start] = i + 1 ;
            start--;
            val--; 
        }
    }
    vector<int> s(m + 1) ;
    for(int i = n - 1; i >= 0; i--){
        s[ans[i]] = i ; 
    }
    debug() << imie(ans) ;
    debug() << imie(s) ;
    int cur = -1 ;
    for(int i = 0; i < m; i++){
        int position_current_platform = s[i + 1] ;
        debug() << imie(position_current_platform) ;
        if ( cur + d >= position_current_platform ) {
            cur = n + 1 ;
            break ;
        }
        for(int j = 0; j < p[i]; j++){
            ans[position_current_platform + j] = 0 ; 
        }
        debug() << imie(ans) ;
        for(int j = 0; j < p[i]; j++){
            ans[cur + d + j] = i + 1 ; 
        }
        debug() << imie(ans) ;
        debug() << imie(p[i]) ;
        cur = cur + d + p[i] - 1;
        debug() << imie(cur) ;
    }
    if ( cur + d >= n ) {
        cout << "YES" << endl;
        for(int &c : ans){
            cout << c << ' ' ;
        }
        cout << endl ;
        debug() << imie(ans) ;
    }
    else {
        cout << "NO" << endl;
    }
    return 0; 
}
// 0 1 2 3 4 5 6
//       1 2 2 3

// cur = -1 ;
// cur += d ;
// cur + d >= start_of_next_platform_postion // done 
// 
// if not 
// 
// the next_platform should be on cur + d ;
// 
// cur = cur + d + (length_of_platfom - 1)

