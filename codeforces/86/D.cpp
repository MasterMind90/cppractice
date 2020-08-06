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
const ll N = 1e6 + 10 ;
const ll INF = 1e18 + 10 ;
int block = 0 ;
struct Q{
    int L , R , idx;
    // bool operator<(const Q &c){
    //     if ( L / block != c.L / block ){
    //         return L / block < c.L / block ;
    //     }
    //     return R < c.R ;
    // }
};
// bool compare(Q &x , Q &y){
//     if ( x.L / block != y.L / block ){
//         return x.L / block < y.L / block ;
//     }
//     return x.R < y.R ;
// }
// bool compare(Q &x , Q &y){
//     return make_pair(x.L / block, x.R) < make_pair(y.L / block, y.R) ;
// }
bool compare(Q &x , Q &y){
    if ( x.L / block != y.L / block ) {
        return x.L / block < y.L / block ;
    }
    if ( (x.L / block) & 1 ){
        return x.R < y.R ;
    }
    return x.R > y.R ;
}
signed main(){
    fastio
    int n , t ;
    cin >> n >> t ;
    block = (int)sqrt(n + 0.0) + 1 ;
    vector<int> v(n) ;
    // int v[n] ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    vector<Q> q(t) ;
    // Q q[t] ;
    for(int i = 0; i < t; i++){
        cin >> q[i].L >> q[i].R ;
        q[i].L-- , q[i].R--; 
        q[i].idx = i ;
    }
    sort(q.begin(), q.end(), compare) ;
    vector<int> mp(N) ;
    // int mp[N] = {0} ;
    // memset(mp, 0, sizeof mp); 
    mp[v[0]]++;
    int answer = v[0];
    int curL = 0, curR = 0 ;
    vector<int> ans(t) ;
    for(int i = 0; i < t; i++){
        int L = q[i].L , R = q[i].R , idx = q[i].idx;
        debug() << imie(L) imie(R) imie(answer) ;
        while(curL > L){
            curL--;
            int &x = v[curL] ;
            if ( mp[x] > 0 ) {
                answer -= mp[x] * mp[x] * x ;
            }
            mp[x]++ ;
            answer += mp[x] * mp[x] * x ;
        }
        while(curR < R){
            curR++;
            int &x = v[curR] ;
            if ( mp[x] > 0 ) {
                answer -= mp[x] * mp[x] * x ;
            }
            mp[x]++ ;
            answer += mp[x] * mp[x] * x ;
        }
        while(curL < L){
            int &x = v[curL] ;
            if ( mp[x] > 0 ){
                answer -= mp[x] * mp[x] * x ; 
                mp[x]-- ;
                answer += mp[x] * mp[x] * x ;
            }
            curL++;
        }
        while(curR > R){
            int &x = v[curR] ;
            if ( mp[x] > 0 ){
                answer -= mp[x] * mp[x] * x ; 
                mp[x]-- ;
                answer += mp[x] * mp[x] * x ;
            }
            curR-- ;
        }
        ans[idx] = answer ;
    }
    for(int &c : ans){
        cout << c << endl;
    }
    return 0; 
}