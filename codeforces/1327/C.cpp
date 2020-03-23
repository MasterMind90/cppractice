#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n , m , k ;
    cin >> n >> m >> k ; 
    vector<char> ans ; 
    for(int i = 0; i < m - 1; i++){
        ans.push_back('L');
    }
    for(int i = 0; i < n - 1; i++){
        ans.push_back('U');
    }
    for(int i = 0; i < n; i++){
        if ( i % 2 == 0 ){
            for(int j = 0; j < m - 1; j++){
                ans.push_back('R') ;
            }
        }
        else {
            for(int j = 0; j < m - 1; j++){
                ans.push_back('L') ;
            }
        }
        if ( i != n - 1 ){
            ans.push_back('D');
        }
    }
    cout << ans.size() << endl;
    for(char &c : ans){
        cout << c ;
    }
    cout << endl;
    return 0; 
}