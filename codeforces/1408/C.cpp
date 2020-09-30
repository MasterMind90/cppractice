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
#define int long long
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
void solve(){
    int n , l ;
    cin >> n >> l ;
    vector<long double> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    v.push_back(l) ;
    vector<long double> diffLeft ;
    int last = 0 ;
    for(int i = 0; i < n; i++){
        diffLeft.push_back((v[i] - last) / (double) (i + 1)) ;
        last = v[i] ;
    }
    diffLeft.push_back((l - last) / double (n + 1)) ;
    debug() << imie(diffLeft) ;
    vector<long double> diffRight ;
    last = l ;
    for(int i = n - 1; i >= 0; i--){
        diffRight.push_back((last - v[i]) / (double) (n - i)) ;
        last = v[i] ;
    }
    diffRight.push_back(v[0] / (double) ( n + 1 )) ;
    debug() << imie(diffRight) ;
    int x = (int) diffLeft.size() ;
    int y = (int) diffRight.size() ;
    vector<long double> sumFirst(x + 1) ;
    vector<long double> sumSecond(x + 1) ;
    for(int i = 0; i < x; i++){
        sumFirst[i + 1] = sumFirst[i] + diffLeft[i] ;
    }
    for(int i = 0; i < y; i++){
        sumSecond[i + 1] = sumSecond[i] + diffRight[i] ;
    }
    debug() << imie(sumFirst) ;
    debug() << imie(sumSecond) ;
    long double L = 1 , R = l - 1 ;
    long double ans = -1 ;
    // while(L <= R){
    for(int rep = 0; rep < 200; rep++){
        long double mid = L + (R - L) / 2.0 ;
        int index = upper_bound(v.begin(), v.end(), mid) - v.begin() ;
        index-- ;
        debug() << imie(index) ;
        long double time = sumFirst[index + 1] ;
        time += (mid - (index == -1 ? 0 : v[index]) ) / (double) (index + 2) ;
        index = lower_bound(v.begin(), v.end(), mid) - v.begin() ;
        // debug() << imie(index) imie(v[index]);
        long double time2 = sumSecond[y - index - 1];
        time2 += (v[index] - mid) / double (y - index) ;
        debug() << imie(mid) imie(time) imie(time2) imie(y - index) ;
        if ( time >= time2 ) {
            ans = time ;
            R = mid ;
        }
        else L = mid ;
    }
    cout << fixed << setprecision(20) << ans << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}