#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    string s , t ;
    cin >> s >> t ; 
    int n = (int) s.size() ; 
    int m = (int) t.size() ; 
    vector<int> pos[26] ; 
    for(int i = 0; i < n; i++){
        pos[s[i] - 'a'].push_back(i) ; 
    }
    for(int i = 0; i < m; i++){
        if ( (int)pos[t[i] - 'a'].size() == 0 ){
            cout << -1 << endl;
            return ; 
        }
    }
    int val = -1 ; 
    int ans = 0 ; 
    for(int i = 0; i < m; i++){
        int cur = t[i] - 'a' ; 
        vector<int> &v = pos[cur] ; 
        int index = upper_bound(v.begin(), v.end(), val) - v.begin() ; 
        if ( index == (int)v.size() ){
            val = -1 ;
            index = upper_bound(v.begin(), v.end(), val) - v.begin();
            ans++; 
        }
        val = v[index] ; 
    }
    cout << ans + 1 << endl;
}
int main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}