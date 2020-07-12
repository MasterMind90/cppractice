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
int popcount(int x){
    int cnt = 0 ;
    for(int i = 0; i < 32; i++){
        if ( (1LL << i) & x ) cnt++ ;
    }
    return cnt ;
}
string toBin(int x){
    string ans = "" ; 
    for(int i = 0; i < 32; i++){
        if ( (1LL << i) & x ) ans.push_back('1') ;
        else ans.push_back('0') ;
    }
    reverse(ans.begin(), ans.end()) ;
    return ans ;
}
int fast(int a, int b, int mod){
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a ;
    int y = fast(a, b / 2, mod) ;
    int ans = (y * y) % mod ;
    if ( b & 1 ) ans *= a ;
    return ans % mod ;
}
signed main(){
    fastio
    vector<int> v(2e5 + 5, 0) ;
    for(int i = 1; i < 2e5 + 5; i++){
        int x = i ;
        int cnt = 0 ;
        int y = popcount(x) ;
        while(x != 0){
            int c = popcount(x) ;
            x %= c ;
            cnt++;
        }
        v[i] = cnt ;
        // if ( cnt == 4 ) 
        // debug() << imie(i) imie(y) imie(toBin(i)) imie(cnt)  ;
    }
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int cnt = 0 ;
    for(char &c : s){
        if ( c == '1' ) cnt++ ;
    }
    bool isOdd = s[n - 1] == '1' ? true : false ;
    if ( cnt == 1 ) {
        for(int i = 0; i < n; i++){
            if ( i == n - 1 && !isOdd ) {
                cout << 2 << endl;
            }
            else if ( s[i] == '0' ) {
                if ( isOdd ){
                    cout << 2 << endl;
                }
                else {
                    cout << 1 << endl;
                }
            }
            else{
                cout << 0 << endl;
            }
        }
        return 0; 
    }
    int high = 0 , low = 0 ;
    for(int i = 0; i < n; i++){
        if ( s[i] == '1' ){
            high += fast(2, n - i - 1, cnt + 1) ;
            low += fast(2, n - i - 1, cnt - 1 ) ;
        }
    }
    debug() << imie(high) ;
    debug() << imie(low) ;
    for(int i = 0; i < n; i++){
        if ( s[i] == '0' ) {
            int x = high ;
            x += fast(2, n - i - 1, cnt + 1 ) ;
            cout << 1 + v[x % (cnt + 1)] << endl;
            debug() << imie(x) ;
        }
        else{
            int x = low ;
            x -= fast(2, n - i - 1, cnt - 1 ) ;
            x = ( x % (cnt - 1) + (cnt - 1) ) % (cnt - 1) ;
            cout << 1 + v[x % (cnt - 1)] << endl; 
            debug() << imie(x) ;
        }
    }

    // return 0 ;
    // int n ;
    // cin >> n ;
    // string s ;
    // cin >> s; 
    // int cnt = 0 ;
    // for(int i = 0; i < n; i++){
    //     if ( s[i] == '1' ) cnt++ ;
    // }
    // bool isOdd = s[n - 1] == '1' ? true : false ;
    // for(int i = 0; i < n; i++){
    //     int newCnt = cnt ;
    //     if ( s[i] == '0' ) newCnt++ ;
    //     if ( newCnt == 1 ) {
    //         cout << 1 << endl;
    //     }
    //     else if ( isOdd ) {

    //     }
    //     else{

    //     }
    // }
    return 0; 
}