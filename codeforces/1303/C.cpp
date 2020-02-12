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
void solve(){
    string s ;
    cin >> s ; 
    int n = (int) s.size() ; 
    vector<set<char> > adj(26) ; 
    if ( n > 1 ) {
        adj[s[0] - 'a'].insert(s[1]) ; 
        adj[s[n - 1] - 'a'].insert(s[n - 2]) ; 
    }
    for(int i = 1; i < n - 1; i++){
        adj[s[i] - 'a'].insert(s[i - 1]) ; 
        adj[s[i] - 'a'].insert(s[i + 1]) ; 
    }
    int ones = 0 ; 
    for(int i = 0; i < 26; i++){
        if ( adj[i].size() == 1 ) ones++ ; 
        else if ( adj[i].size() > 2 ){
            cout << "NO" << endl;
            return ; 
        }
    }
    if ( ones > 2 ) {
        cout << "NO" << endl;
        return ; 
    }
    if ( ones == 0 && n != 1){
        cout << "NO" << endl;
        return ; 
    }
    string ans = ""; 
    queue<int> q ; 
    for(int i = 0; i < 26; i++){
        if ( adj[i].size() == 1 ){
            q.push(i) ; 
            break ; 
        }
    }
    vector<int> used(26) ; 
    while(not q.empty()){
        int f = q.front() ; q.pop() ; 
        used[f] = true ; 
        ans.push_back(f + 'a') ; 
        for(char c : adj[f]){
            if ( used[c - 'a'] ) continue ;
            q.push(c - 'a') ; 
        }
    }
    string notUsed = "" ; 
    for(int i = 0; i < 26; i++){
        if ( !used[i]) notUsed.push_back(i + 'a') ;
    }
    while(not notUsed.empty()){
        ans.push_back(notUsed.back());
        notUsed.pop_back() ; 
    }
    cout << "YES" << endl;
    cout << ans << endl;
}
signed main(){
    fastio
    int t ; 
    cin >> t ;
    while(t--) solve() ;
    return 0 ;
}