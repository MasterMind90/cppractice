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
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(0) ;
using ll = long long ;
const ll INF = 1e10 + 10 ;
const ll N = 1e10 ;
int main(){
    fastio
    int t ;
    cin >> t ;
    while(t--){
        string s ;
        cin >> s ; 
        int n = (int) s.size() ; 
        vector<int> v[2] ; 
        for(int i = 0; i < n; i++){
            int c = s[i] - '0' ; 
            v[c & 1].push_back(i) ; 
        }
        reverse(v[0].begin(), v[0].end()) ; 
        reverse(v[1].begin(), v[1].end()) ; 
        string ans = "" ; 
        while(!v[0].empty() || !v[1].empty()){
            if ( not v[0].empty() && not v[1].empty() ){
                int a = v[0].back() , b = v[1].back() ; 
                if ( s[a] < s[b] ){
                    ans += s[a] ; 
                    v[0].pop_back() ; 
                }
                else {
                    ans += s[b] ; 
                    v[1].pop_back() ; 
                }
            }
            else if ( not v[0].empty() ){
                int a = v[0].back();
                v[0].pop_back();
                ans += s[a] ; 
            }
            else{
                int a = v[1].back() ;
                v[1].pop_back();
                ans += s[a] ; 
            }
        }
        cout << ans << endl;
    }
    return 0 ;
}