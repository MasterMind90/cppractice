#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sim template < class c
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
~debug() { cerr << endl; }
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
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
string s[2] ; 
int n ; 
bool dfs(int x,int y,int from){
    // handle outside cases
    if ( y == n && x == 1 ){
        return true ; 
    }
    if ( x < 0 || x > 1 ) return false;
    if ( y < 0 || y >= n ) return false;
    if ( x == 0 ){
        if ( from == 0 ){
            if ( s[x][y] >= '3' && s[x][y] <= '6' ){
                if ( dfs(x + 1, y, 1) ) return true ;
            }
            else{
                if ( dfs(x, y + 1, 0) ) return true ;
            }
        }
        else{
            if ( s[x][y] >= '3' && s[x][y] <= '6' ){
                if ( dfs(x, y + 1, 0) ) return true ;
            }
        }
    }
    else{
        if ( from == 0 ){
            if ( s[x][y] >= '3' && s[x][y] <= '6' ){
                if ( dfs(x - 1, y, 1) ) return true ;
            }
            else{
                if ( dfs(x, y + 1, 0) ) return true ;
            }
        }
        else{
            if ( s[x][y] >= '3' && s[x][y] <= '6' ){
                if ( dfs(x, y + 1, 0) ) return true ;
            }
        }
    }
    return false;
}
int main(){
    fastio
    int q ; 
    cin >> q ;
    while(q--){
        cin >> n ; 
        cin >> s[0] >> s[1] ; 
        if ( dfs(0,0,0) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0 ;
}


