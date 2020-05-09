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
int n ; 
vector<int> ans ; 
bool dfs(int x, int a, int b, int c){
    if ( x == n ){
        debug() << imie(ans) ;
        for(int &p : ans){
            cout << p ;
        }
        cout << endl;
        return true ;
    }
    if ( ans.empty() ){
        if ( b || c ){
            ans.push_back(1) ;
            if ( dfs(x + 1, a, b, c) ) return true ;
            ans.pop_back() ;
        }
        if ( a || b ){
            ans.push_back(0) ;
            if ( dfs(x + 1, a, b, c) ) return true ;
            ans.pop_back() ;
        }
    }
    else{
        int last = ans.back() ;
        if ( last == 1 ){
            if ( b ) {
                ans.push_back(0) ;
                if ( dfs(x + 1, a, b - 1, c) ) return true ;
                ans.pop_back() ;
            }
            if ( c ) {
                ans.push_back(1) ;
                if ( dfs(x + 1, a, b, c - 1) ) return true ;
                ans.pop_back() ;
            }
        }
        else{
            if ( a ){
                ans.push_back(0) ;
                if ( dfs(x + 1, a - 1, b, c) ) return true ;
                ans.pop_back() ;
            }
            if ( b ){
                ans.push_back(1) ;
                if ( dfs(x + 1, a, b - 1, c) ) return true ;
                ans.pop_back() ;
            }
            if ( c && b ){
                ans.push_back(1) ;
                if ( dfs(x + 1, a, b - 1 , c) ) return true ;
                ans.pop_back() ;
            }
        }
    }
    return false ;
}
void solve(){
    int a , b , c ;
    ans.clear() ;
    cin >> a >> b >> c ; 
    n = a + b + c + 1 ;
    dfs(0, a, b, c) ;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}