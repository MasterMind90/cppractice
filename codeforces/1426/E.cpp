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
    int n ;
    cin >> n ;
    vector<pair<int,int> > a(3) , b(3) ;
    // 0 rock
    // 1 sicc
    // 2 pap
    for(int i = 0; i < 3; i++){
        cin >> a[i].first ;
        a[i].second = i ;
    }
    for(int i = 0; i < 3; i++){
        cin >> b[i].first ;
        b[i].second = i ;
    }
    sort(a.begin(), a.end()) ;
    int nix = INF ;
    int nax = 0 ;
    do{
        sort(b.begin(), b.end()) ;
        do{
            int winAlice = 0 ;
            auto x = a ;
            auto y = b ;
            while(not x.empty() && not y.empty()){
                debug() << imie(x) ;
                debug() << imie(y) ;
                int A = x.back().first , AT = x.back().second ; x.pop_back() ;
                int B = y.back().first , BT = y.back().second ; y.pop_back() ;
                if ( A == 0 && B == 0 ){
                    continue ;
                }
                else if ( A == 0 ) {
                    y.push_back(make_pair(B, BT)) ;
                    continue ;
                }
                else if ( B == 0 ) {
                    x.push_back(make_pair(A, AT)) ;
                    continue ;
                }
                if ( AT == 0 && BT == 0 ){
                    if ( A != B ) {
                        if ( A > B ){
                            x.push_back(make_pair(A - B, AT)) ;
                        }
                        else if ( A < B ) {
                            y.push_back(make_pair(B - A, BT)) ;
                        }
                    }
                }
                else if ( AT == 2 && BT == 0 ) {
                    winAlice += min(A, B) ;
                    if ( A > B ) {
                        x.push_back(make_pair(A - B, AT)) ;
                    }
                    else if ( A < B ){
                        y.push_back(make_pair(B - A, BT)) ;
                    }
                }
                else if ( AT == 0 && BT == 1 ) {
                    winAlice += min(A, B) ;
                    if ( A > B ) {
                        x.push_back(make_pair(A - B, AT)) ;
                    }
                    else if ( A < B ){
                        y.push_back(make_pair(B - A, BT)) ;
                    }
                }
                else if ( AT == 1 && BT == 2 ) {
                    winAlice += min(A, B) ;
                    if ( A > B ) {
                        x.push_back(make_pair(A - B, AT)) ;
                    }
                    else if ( A < B ){
                        y.push_back(make_pair(B - A, BT)) ;
                    }
                }
                else{
                    if ( A > B ) {
                        x.push_back(make_pair(A - B, AT)) ;
                    }
                    else if ( A < B ){
                        y.push_back(make_pair(B - A, BT)) ;
                    }
                }
            }
            debug() << imie(winAlice) ;
            nix = min(nix, winAlice) ;
            nax = max(nax, winAlice) ;
        }while(next_permutation(b.begin(), b.end())) ;
    }while(next_permutation(a.begin(), a.end()));
    cout << nix << ' ' << nax << endl;
}
signed main(){
    fastio
    int t ;
    t = 1 ;
    while(t--) solve() ;
    return 0; 
}