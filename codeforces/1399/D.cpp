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
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    set<int> pos[2] ;
    for(int i = 0; i < n; i++){
        char &c = s[i] ;
        pos[c - '0'].insert(i) ;
    }
    vector<int> color(n) ;
    int start = 1 ;
    while((int)pos[0].size() > 0 || (int)pos[1].size() > 0){
        int cur = -1 ;
        int flag = 0 ; 
        int len = 0 ;
        vector<int> p1 ;
        while(true){
            set<int> &t = pos[flag] ;
            auto it = t.upper_bound(cur) ;
            if ( it == t.end() ) break ;
            cur = *it ;
            p1.emplace_back(cur) ;
            len++ ;
            flag = !flag ;
        }
        debug() << imie(p1) ;
        cur = -1 ;
        flag = 1 ;
        int len2 = 0 ;
        vector<int> p2 ;
        while(true){
            set<int> &t = pos[flag] ;
            auto it = t.upper_bound(cur) ;
            if ( it == t.end() ) break ;
            cur = *it ;
            p2.emplace_back(cur) ;
            len2++ ;
            flag = !flag ;
        }
        debug() << imie(p2) ;
        if ( p1.size() > p2.size() ) {
            for(int &c : p1){
                color[c] = start ;
            }
            int f = 0 ;
            for(int &c : p1){
                pos[f].erase(c) ;
                f = !f ;
            }
        }
        else{
            for(int &c : p2){
                color[c] = start ;
            }
            int f = 1 ;
            for(int &c : p2){
                pos[f].erase(c) ;
                f = !f ;
            }
        }
        start++ ;
    }
    cout << start - 1 << endl;
    for(int &c : color){
        cout << c << ' ' ;
    }
    cout << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t; 
    while(t--) solve() ;
    return 0; 
}
