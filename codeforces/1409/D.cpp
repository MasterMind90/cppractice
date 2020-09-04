#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int unsigned long long
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
int get(int x, int y){
    for(int i = 0; i < y; i++){
        x *= 10LL ;
    }
    return x ;
}
void solve(){
    int n , s ;
    cin >> n >> s ;
    string x ;
    stringstream ss ;
    ss << n ;
    ss >> x ;
    int cur = 0 ;
    for(int i = 0; i < (int) x.size(); i++){
        cur += (x[i] - '0') ;
    }
    if ( cur <= s ) {
        cout << 0 << endl;
        return ;
    }
    int ans = get(1, (int)x.size()) - n ;
    cur = 0 ;
    int sum = 0 ;
    int m = (int) x.size() ;
    for(int i = 0; i < (int) x.size(); i++){
        cur += x[i] - '0' ;
        if ( cur + 1 <= s && x[i] != '9' ) {
            debug() << imie(sum) ;
            debug() << imie(get(x[i] - '0' + 1, m - i - 1)) ;
            ans = min(ans, sum + get(x[i] - '0' + 1, m - i - 1) - n) ;
            sum += get(x[i] - '0', m - i - 1) ;
        }
        else sum += get(x[i] - '0' , m - i - 1) ;
        // if ( cur + 1 < s && x[i] == '9' ) {
        //     int tmp = cur - (x[i] - '0') ;

        // }
        debug() << imie(cur) imie(sum) ;
    }
    cout << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}