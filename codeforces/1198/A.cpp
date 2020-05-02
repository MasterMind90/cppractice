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
signed main(){
    fastio
    int n , b ;
    cin >> n >> b ; 
    b *= 8 ; 
    vector<int> v(n) ;
    map<int, int> mp ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
        mp[v[i]]++;
    }
    int K = (int) mp.size() ;
    auto go = [&](int mid){
        for(int i = 0; ; i++){
            if ( (1LL << i) >= mid ) return i ; 
        }
        return 0LL ;
    };
    int L = 1, R = K ; 
    int ans = -1 ;
    while(L <= R){
        int mid = L + (R - L) / 2;
        int t = go(mid) ;
        if ( t * n <= b ){
            ans = mid ;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    assert(ans != -1) ;
    sort(v.begin(), v.end()) ;
    debug() << imie(v) ;
    vector<int> cnt(n) ;
    cnt[0] = 1 ;
    for(int i = 1; i < n; i++){
        if ( v[i] != v[i - 1] ) cnt[i] = 1 ;
    }
    for(int i = 1; i < n; i++){
        cnt[i] += cnt[i - 1] ;
    }
    debug() << imie(cnt) ;
    int answer = 1e9 + 10 ;
    for(int i = 0; i < n; i++){
        int l = v[i] , r = -1;
        int val = lower_bound(cnt.begin(), cnt.end(), cnt[i] + ans) - cnt.begin() ;
        if ( val == n ) r = v[n - 1];
        else r = v[val] - 1;
        int firstPart = lower_bound(v.begin(), v.end(), l) - v.begin() ;
        int secondPart = n - (upper_bound(v.begin(), v.end(), r) - v.begin()) ;
        debug() << imie(l) imie(r) imie(firstPart + secondPart) ;
        answer = min(answer, firstPart + secondPart) ;
    }
    cout << answer << endl;
    return 0; 
}