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
signed main(){
    fastio
    int n , t ;
    cin >> n >> t ;
    vector<int> v ;
    for(int i = 0; i <= n / 2; i++){
        int x ;
        cin >> x ;
        v.emplace_back(x) ;
    }
    vector<int> b ; 
    for(int i = n / 2 + 1; i < n; i++){
        int x ;
        cin >> x ;
        b.emplace_back(x) ;
    }
    debug() << imie(v) ;
    debug() << imie(b) ;
    n = (int) v.size() ;
    int m = (int) b.size() ;
    vector<int> sumA ; 
    for(int subset = 0; subset < (1 << n); subset++){
        int sum = 0 ;
        for(int i = 0; i < n; i++){
            if ( (1 << i) & subset ){
                sum += v[i] ;
            }
        }
        sumA.emplace_back(sum) ;
    }
    vector<int> sumB ; 
    for(int subset = 0; subset < (1 << m); subset++){
        int sum = 0 ;
        for(int i = 0; i < m; i++){
            if ( (1 << i) & subset ){
                sum += b[i] ;
            }
        }
        sumB.emplace_back(sum) ;
    }
    sort(sumA.begin(), sumA.end()) ;
    sort(sumB.begin(), sumB.end()) ;
    int ans = 0 ;
    for(int i = 0; i < (int)sumA.size(); i++){
        int L = 0 , R = (int)sumB.size() - 1;
        int cur = -1 ;
        while(L <= R){
            int mid = L + (R - L) / 2 ;
            if ( sumA[i] + sumB[mid] <= t ){
                cur = mid ;
                L = mid + 1 ;
            }
            else R = mid - 1 ;
        }
        if ( cur != -1 ) ans = max(ans, sumA[i] + sumB[cur]) ;
    }
    cout << ans << endl;
    return 0; 
}