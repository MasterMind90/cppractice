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
    int n ; 
    cin >> n ;
    vector<int> a(n) ;
    map<int,int> MP ; 
    int sum = 0 ;
    for(int i = 0; i < n; i++){
        cin >> a[i] ; 
        if ( a[i] == 1 ) sum++ ; 
        else sum--;
        MP[sum] = i + 1; 
    }
    vector<int> b(n) ; 
    for(int i = 0; i < n; i++){
        cin >> b[i] ; 
    }
    reverse(b.begin(), b.end());
    map<int,int> mp ; 
    int cur = 0 ; 
    for(int i = 0; i < n; i++){
        if ( b[i] == 1 ) cur++ ;
        else cur-- ; 
        mp[cur] = i + 1 ; 
    }
    int ans = 0; 
    auto it = mp.find(0) ;
    if ( it != mp.end() ) ans = it->second ;
    cur = 0 ; 
    for(int i = 0; i < n; i++){
        if ( a[i] == 1 ) cur++ ; 
        else cur--;
        it = mp.find(-cur) ;
        if ( it != mp.end() )
            ans = max(ans, i + 1 + it->second);
    }
    it = MP.find(0) ;
    if ( it != MP.end() ) ans = max(ans, it->second) ;
    cur = 0 ; 
    for(int i = 0; i < n; i++){
        if ( b[i] == 1 ) cur++ ; 
        else cur--;
        it = MP.find(-cur) ;
        if ( it != MP.end() )
            ans = max(ans, i + 1 + it->second);
    }
    cout << 2 * n - ans << endl;
}
int main(){
    fastio
    ll t ;
    cin >> t ;
    while(t--){
        solve() ; 
    }
    return 0; 
}