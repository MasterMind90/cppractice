#ifndef LOCAL
#pragma GCC optimize("O3")
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
    int n , k; 
    cin >> n >> k; 
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    sort(v.begin(), v.end()) ;
    set<int> taken ;
    int nax = 0 ;
    auto find = [&](int x){
        int L = 0, R = 3e5 ;
        int ans = -1;
        while(L <= R){
            int mid = L + (R - L) / 2;
            if ( taken.count(mid * k + x) == 0 ){
                ans = mid ;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        return k * ans + x ;
    };
    bool ok = false ;
    for(int i = 0; i < n; i++){
        if ( v[i] % k == 0 ) continue ;
        ok = true ;
        int cur = k - v[i] % k  ;
        debug() << imie(v[i]) imie(cur) ;
        if ( taken.count(cur) == 0 ){
            nax = max(nax, cur + 1) ;
            taken.insert(cur) ;
        }
        else{
            cur = find(cur) ;
            nax = max(nax, cur + 1) ;
            taken.insert(cur) ;
        }
    }
    cout << nax << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--){
        solve() ;
    }
    return 0; 
}