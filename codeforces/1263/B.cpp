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
const ll MOD = 1e9 + 7 ;
const ll N = 3e6 + 10 ;
const ll INF = 1e18 + 10 ;
int main(){
    fastio
    int t ;
    cin >> t ;
    while(t--){
        int n ; 
        cin >> n ; 
        vector<string> v(n) ; 
        map<string,int> mp ; 
        bool ok = false ;
        for(int i = 0; i < n; i++){
            cin >> v[i] ; 
            mp[v[i]]++ ; 
            if ( mp[v[i]] > 1 ) ok = true ; 
        }
        if ( !ok ){
            cout << 0 << endl; 
            for(int i = 0; i < n; i++){
                cout << v[i] << endl;
            }
            continue ; 
        }
        int ans = 0 ; 
        for(auto &c : mp){
            ans += c.second - 1 ;
        }
        cout << ans << endl;
        set<char> s[4] ; 
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < n; j++){
                s[i].insert(v[j][0]) ; 
            }
        }
        set<char> after[4] ;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 10; j++){
                if ( s[i].find(j + '0') == s[i].end() ) after[i].insert(j + '0') ; 
            }
        }
        map<string,int> cnt ; 
        for(int i = 0; i < n; i++){
            cnt[v[i]]++ ; 
            if ( cnt[v[i]] > 1 ){
                for(int j = 0; j < 4; j++){
                    if ( after[j].empty() ) continue ; 
                    v[i][j] = *after[j].begin() ; 
                    after[j].erase(after[j].begin()) ; 
                    break; 
                }
            }
            cout << v[i] << endl;
        }
    }
    return 0; 
}
/*
0139
3139
3139
3139
3139
*/