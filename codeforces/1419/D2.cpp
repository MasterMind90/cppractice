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
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    multiset<int> ms ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
        ms.insert(v[i]) ;

    }
    sort(v.rbegin(), v.rend()) ;
    vector<int> ans(n) ;
    debug() << imie(ms) ;
    for(int i = 0, j = 0; i < n; i += 2, j++){
        ans[i] = v[j] ;
        ms.erase(ms.find(v[j])) ;
    }
    debug() << imie(ms) ;
    debug() << imie(ans) ;
    auto best = [&](int a, int b){
        auto it = ms.lower_bound(min(a, b));
        if ( it == ms.begin() ){
            it = ms.end() ;
            it--;
            int val = *it ;
            ms.erase(it) ;
            return val ;
        }
        it--;
        int val = *it ;
        ms.erase(it) ;
        return val ;
    };
    for(int i = 1; i < n - 1; i++){
        if ( ans[i] == 0 ) {
            int b = best(ans[i - 1], ans[i + 1]) ;
            ans[i] = b ; 
        }
    }
    // for(int i = n & 1 ? n - 2 : n - 1, j = n - 1; i >= 0 ; i -= 2, j--){
    //     ans[i] = v[j] ;
    // }
    debug() << imie(ms) ;
    for(int i = 0; i < n && not ms.empty(); i++){
        if ( ans[i] == 0 ) {
            ans[i] = *ms.begin() ;
            ms.erase(ms.begin()) ;
        }
    }
    int answer = 0 ;
    for(int i = 1; i < n - 1; i++){
        if ( ans[i] < ans[i - 1] && ans[i] < ans[i + 1] ) answer++ ;
    }
    cout << answer << endl;
    for(int &c : ans){
        cout << c << ' ' ;
    }
    cout << endl;
    return 0; 
}