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
    vector<pair<int,int> > a(n) ;
    for(int i = 0; i < n; i++){
        cin >> a[i].first ;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].second ;
    }
    sort(a.begin(), a.end()) ;
    int cur = 0 ; 
    int sum = 0 ;
    priority_queue<int> q ;
    int ans = 0 ; 
    debug() << imie(a) ;
    for(int i = 0; i < n; i++){
        debug() << "Before: " imie(i) imie(a[i]) imie(cur) imie(sum) ;
        if ( q.empty() ){
            cur = a[i].first ;
            sum = a[i].second ;
            q.push(a[i].second) ;
        }
        else{
            if ( cur == a[i].first ) {
                q.push(a[i].second) ;
                sum += a[i].second ;
            }
            else{
                while(not q.empty() && a[i].first != cur ){
                    int t = q.top() ; q.pop() ;
                    sum -= t ;
                    ans += sum ;
                    cur++ ;
                }
                q.push(a[i].second) ;
                cur = a[i].first ;
                sum += a[i].second ;
            }
        }
        debug() << "After: " imie(i) imie(a[i]) imie(cur) imie(sum) ;
    }
    while(not q.empty()){
        int t = q.top() ; q.pop() ;
        sum -= t ;
        ans += sum ;
    }
    cout << ans << endl;
    return 0; 
}