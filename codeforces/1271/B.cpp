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
const ll N = 2e6 + 10 ;
const ll INF = 1e9 + 10 ;
int main(){
    fastio
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int bs = 0, ws = 0 ;
    for(char &c : s){
        if ( c == 'B' ) bs++;
        else ws++;
    }
    if ( ws == 0 ){
        cout << 0 << endl;
        return 0 ; 
    }
    if ( bs == 0 ){
        cout << 0 << endl;
        return 0 ; 
    }
    if ( ws % 2 == 1 && bs % 2 == 1 ){
        cout << -1 << endl;
        return 0 ; 
    }
    vector<int> ans ;
    // all blacks ; 
    string t = s ;
    for(int i = 0; i < n - 1; i++){
        if (s[i] == 'W' ){
            ans.push_back(i) ;
            s[i] = 'B' ; 
            if ( s[i + 1] == 'B' ) s[i + 1] = 'W' ; 
            else s[i + 1] = 'B' ; 
        }
    }
    for(int i = 0; i < n - 1; i++){
        if (s[i] == 'B' ){
            ans.push_back(i) ;
            s[i] = 'W' ; 
            if ( s[i + 1] == 'B' ) s[i + 1] = 'W' ; 
            else s[i + 1] = 'B' ; 
        }
    }
    if ( s[n - 1] == 'B' ){
        for(int i = 0; i < n - 1; i++){
            if (s[i] == 'W' ){
                ans.push_back(i) ;
                s[i] = 'B' ; 
                if ( s[i + 1] == 'B' ) s[i + 1] = 'W' ; 
                else s[i + 1] = 'B' ; 
            }
        }
    }
    cout << (int) ans.size() << endl;
    for(int &c : ans){
        cout << c + 1 << ' ' ;
    }
    cout << endl;
    return 0; 
}