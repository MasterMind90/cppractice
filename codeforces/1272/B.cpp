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
const ll INF = 1e18 + 10 ;
void solve(){
    string s ;
    cin >> s ; 
    int n = (int) s.size() ; 
    int left = 0 ; 
    int right = 0 ; 
    int up = 0 ; 
    int down = 0 ; 
    for(int i = 0; i < n; i++){
        if ( s[i] == 'L' ) left++ ; 
        else if ( s[i] == 'R' ) right++ ; 
        else if ( s[i] == 'U' ) up++ ; 
        else if ( s[i] == 'D' ) down++ ; 
    }
    if ( left > 0 && right > 0 && up > 0 && down > 0 ){
        int first = min(left, right) ; 
        int second = min(up, down) ; 
        cout << 2 * first + 2 * second << endl;
        for(int i = 0; i < second; i++){
            cout << 'U' ;
        }
        for(int i = 0; i < first; i++){
            cout << 'R' ;
        }
        for(int i = 0; i < second; i++){
            cout << 'D' ;
        }
        for(int i = 0; i < first; i++){
            cout << 'L' ;
        }
        cout << endl;
    }
    else if ( right >= 0 && up > 0 && down > 0 ){
        cout << 2 << endl;
        cout << "UD" << endl;
    }
    else if ( left >= 0 && up > 0 && down > 0 ){
        cout << 2 << endl;
        cout << "UD" << endl;
    }
    else if ( up >= 0 && right > 0 && left > 0 ){
        cout << 2 << endl ; 
        cout << "LR" << endl;
    }
    else if ( down >= 0 && right > 0 && left > 0 ){
        cout << 2 << endl ; 
        cout << "LR" << endl;
    }
    else{
        cout << 0 << endl;
        cout << endl;
    }
}
int main(){
    fastio
    int t ; 
    cin >> t ;
    while(t--){
        solve() ;
    }
    return 0; 
}
