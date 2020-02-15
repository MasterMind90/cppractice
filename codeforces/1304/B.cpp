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
const ll N = 1e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    vector<string> v(n) ; 
    for(int i = 0; i < n; i++){
        cin >> v[i] ; 
    }
    vector<bool> used(n) ; 
    deque<string> dq ; 
    string add ; 
    bool done = false ;
    for(int i = 0; i < n; i++){
        string cur = v[i] ; 
        string rev = cur ; 
        reverse(rev.begin(), rev.end());
        used[i] = true ; 
        bool ok = false ;
        for(int j = 0; j < n; j++){
            if ( not used[j] && v[j] == rev ){
                used[j] = true ; 
                dq.push_front(cur) ; 
                dq.push_back(rev) ; 
                ok = true ;
                break;
            }
        }
        if ( not ok ){
            if ( not done && cur == rev ) {
                add = cur ; 
                done = true ;
            }
        }
    }
    string ans = "" ; 
    if ( dq.size() == 0 ) ans += add ; 
    for(int i = 0; i < dq.size() ;i++){
        if ( i == dq.size() / 2 ){
            ans += add ; 
        }
        ans += dq[i] ; 
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0 ;
}