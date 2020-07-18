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
    int n , k ; 
    cin >> n >> k ; 
    if ( n == 1 ) {
        cout << 0 << endl;
        return 0 ;
    }
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    int ans = INF ; 
    int start = -1 ; 
    for(int i = 1; i <= 2000; i++){
        int cnt = 0 ;
        for(int j = 0; j < n; j++){
            // cout << j + i << ' ' ; 
            if ( v[j] != i + j * k ) { //1 3 5 
                cnt++ ;
            }
        }
        if ( cnt < ans ) {
            start = i ; 
            ans = cnt ;
        }
    }

    // assert(start != -1) ;
    vector<pair<char,pair<int,int> > > answer ;
    for(int i = 0; i < n; i++){
        if ( v[i] == i * k + start ) continue ;
        if ( v[i] < i * k + start ) answer.push_back(make_pair('+',make_pair(i + 1, i * k + start - v[i])));
        else answer.push_back(make_pair('-', make_pair(i + 1, v[i] - (start + i * k))));
    }
    cout << answer.size() << endl;
    for(auto &p : answer){
        cout << p.first << ' ' << p.second.first << ' ' << p.second.second << endl;
    }
    return 0; 
}