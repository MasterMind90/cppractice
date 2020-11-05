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
    int n , m ;
    cin >> n >> m ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    vector<int> w(m) ;
    for(int i = 0; i < m; i++){
        cin >> w[i] ;
    }
    if ( n == 1 ) {
        int ans = INF ;
        for(int i = 0; i < m; i++){
            ans = min(ans, abs(v[0] - w[i])) ;
        }
        cout << ans << endl;
        return 0 ;
    }
    sort(v.begin(), v.end()) ;
    vector<int> first ;
    for(int i = 1; i < n; i += 2) {
        first.emplace_back(v[i] - v[i - 1]) ;
    }
    vector<int> second ; 
    for(int i = 2; i < n; i += 2) {
        second.emplace_back(v[i] - v[i - 1]) ;
    }
    debug() << imie(first) ;
    debug() << imie(second) ;
    int T = (int)first.size() ;
    vector<int> sumFirst(T) ;
    int M = (int) second.size() ;
    vector<int> sumSecond(M) ;
    for(int i = 0; i < T; i++){
        if ( i == 0 ) {
            sumFirst[i] = first[i] ;
        }
        else{
            sumFirst[i] = sumFirst[i - 1] + first[i] ;
        }
    }
    for(int i = 0; i < M; i++){
        if ( i == 0 ) {
            sumSecond[i] = second[i] ;
        }
        else{
            sumSecond[i] = sumSecond[i - 1] + second[i] ;
        }
    }
    debug() << imie(sumFirst) ;
    debug() << imie(sumSecond) ;
    int ans = INF ;
    for(int i = 0; i < m; i++){
        int L = 0, R = n - 1; 
        int index = -1 ;
        while(L <= R){
            int mid = L + (R - L) / 2 ;
            if ( v[mid] <= w[i] ) {
                index = mid ;
                L = mid + 1 ;
            }
            else {
                R = mid - 1 ;
            }
        }
        if ( index == -1 || index == 0 ) {
            ans = min(ans, sumSecond[M - 1] + abs(v[0] - w[i]) ) ;
        }
        else{
            if ( index & 1 ) {
                ans = min(ans, sumFirst[index / 2] + (v[index + 1] - w[i]) + (sumSecond[M - 1] - sumSecond[index / 2]) ) ; 
            }
            else{
                ans = min(ans, sumFirst[index / 2 - 1] + (w[i] - v[index]) + (sumSecond[M - 1] - sumSecond[index / 2 - 1])) ;
            }
        }
    }
    cout << ans << endl;
    return 0; 
}