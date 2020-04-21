#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    int n ;
    cin >> n ; 
    if ( (n / 2) & 1 ){
        cout << "NO" << endl;
        return ;
    }
    vector<int> ans ;
    for(int i = 0; i < n / 2; i++){
        ans.push_back(i * 2 + 2) ;
    }
    vector<int> odd ;
    int cur = 1 ;
    set<int> s ;
    for(int i = 1; i < (int)ans.size(); i+= 2){
        int c = ans[i] + ans[i - 1] ;
        while ( s.count(cur) || s.count(c - cur) ) cur+= 2;
        odd.push_back(c - cur) ;
        odd.push_back(cur) ;
        s.insert(c - cur) ;
        s.insert(cur) ;
        cur+= 2; 
    }
    cout << "YES" << endl;
    for(int &c : ans){
        cout << c << ' ' ;
    }
    for(int &c : odd){
        cout << c << ' ' ;
    }
    cout << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--){
        solve() ;
    }
    return 0; 
}