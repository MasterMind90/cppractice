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
bool check(int n){
    if ( n & 1 ) return true ;
    if ( n == 2 ) return true ;
    vector<int> div ;
    for(int i = 1; i * i <= n; i++){
        if ( n % i == 0 ){
            if ( i != 1 && (i & 1)) div.emplace_back(i) ;
            if ( n / i != i && ((n / i) & 1) ) div.emplace_back(n / i) ;
        }
    }
    for(int &c : div){
        if ( (n / c) % 2 ==  0 && n / c != 2 ){
            return true ;
        }
    }
    return false ;
}
void solve(){
    int n ; 
    cin >> n ; 
    if ( n == 1 ){
        cout << "FastestFinger" << endl;
        return ;
    }
    if ( n & 1 ){
        cout << "Ashishgup" << endl;
        return ;
    }
    int cur = 0 ;
    while(n > 1){
        if ( n == 2 ){
            if ( cur == 0 ){
                cout << "Ashishgup" << endl;
            }
            else 
                cout << "FastestFinger" << endl;
            return ; 
        }
        if ( check(n) ){
            vector<int> div ;
            for(int i = 1; i * i <= n; i++){
                if ( n % i == 0 ){
                    if ( i != 1 && (i & 1)) div.emplace_back(i) ;
                    if ( n / i != i && ((n / i) & 1) ) div.emplace_back(n / i) ;
                }
            }
            int d = -1 ;
            for(int &c : div){
                if ( (n / c) % 2 ==  0 && n / c != 2 ){
                    d = c ;
                    if ( not check(n / c) ) break ;
                }
            }
            n /= d ;
        }
        else{
            if ( cur == 0 ){
                cout << "FastestFinger" << endl;
            }
            else cout << "Ashishgup" << endl;
            return ;
        }
        cur = !cur ;
        // if ( n == 2 ){
        //     if ( cur == 0 ){
        //         cout << "Ashishgup" << endl;
        //     }
        //     else {
        //         cout << "FastestFinger" << endl;
        //     }
        //     return ;
        // }
        // debug() << imie(n) ;
        // debug() << imie(div) ;
        // bool can = false;
        // for(int &c : div){
        //     if ( (n / c) % 2 ==  0 && n / c != 2 ){
        //         n /= c ;
        //         can = true ;
        //         break ;
        //     }
        // }
        // if ( not can ) {
        //     if ( cur == 0 ){
        //         cout << "FastestFinger" << endl;
        //     }
        //     else cout << "Ashishgup" << endl;
        //     return ;
        // }
        // cur = !cur ;
    }
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}