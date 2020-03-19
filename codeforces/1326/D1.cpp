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
const ll MOD = 998244353 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
void solve(){
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    // check longest prefix ; 
    string ans = "" ; 
    auto check = [&](string& s, int x, int y){
        int len = y - x + 1 ;
        for(int i = 0; i < len / 2; i++){
            if ( s[i + x] != s[y - i] ) return false ;
        }
        return true ;
    };
    if ( check(s, 0, n - 1) ){
        cout << s << endl;
        return ;
    }
    pair<int,int> naxPre = {0, 0};
    for(int i = 1; i < n; i++){
        if ( s[i] == s[0] ){
            if ( check(s, 0, i) ){
                naxPre = {0, i};
            }
        }
    }
    string t = s ;
    reverse(t.begin(), t.end()) ;
    pair<int,int> naxSuf = {0, 0};
    for(int i = 1; i < n; i++){
        if ( t[i] == t[0] ){
            if ( check(t, 0, i) ){
                naxSuf = {0, i};
            }
        }
    }
    debug() << imie(naxPre) ; 
    debug() << imie(naxSuf) ; 
    string mid = "" ; 
    int cnt = 0 ; 
    for(int i = 0; i < n / 2; i++){
        if ( s[i] != s[n - i - 1] ){
            int len = n - i - i ;
            mid = s.substr(i, len) ;
            break;
        }
        cnt++ ; 
    }
    debug() << imie(mid) ;
    pair<int,int> midPre = {0, 0} ; 
    for(int i = 1; i < mid.size(); i++){
        if ( mid[i] == mid[0] ){
            if ( check(mid, 0, i) ){
                midPre = {0, i} ; 
            }
        }
    }
    t = mid ; 
    reverse(t.begin(), t.end()) ; 
    pair<int,int> midSuf = {0, 0} ; 
    for(int i = 1; i < t.size(); i++){
        if ( t[i] == t[0] ){
            if ( check(t, 0, i) ){
                midSuf = {0, i} ; 
            }
        }
    }
    auto go = [&](pair<int,int> p){
        return p.second - p.first + 1; 
    };
    debug() << imie(cnt) ; 
    debug() << imie(midPre) ;
    debug() << imie(midSuf) ;
    if ( 2 * cnt + go(midPre) > go(naxPre) && 2 * cnt + go(midPre) > go(naxSuf) ){
        if ( 2 * cnt + go(midPre) > 2 * cnt + go(midSuf) ){
            for(int i = 0; i < cnt + go(midPre); i++){
                cout << s[i] ; 
            }
            for(int i = 0; i < cnt; i++){
                cout << s[n - cnt + i] ; 
            }
            cout << endl;
        }
        else{
            for(int i = 0; i < cnt; i++){
                cout << s[i] ; 
            }
            for(int i = 0; i < cnt + go(midSuf); i++){
                cout << s[n - (cnt + go(midSuf)) + i] ; 
            }
            cout << endl;
        }
    }
    else if ( 2 * cnt + go(midSuf) > go(naxPre) && 2 * cnt + go(midSuf) > go(naxSuf) ){
        if ( 2 * cnt + go(midPre) > 2 * cnt + go(midSuf) ){
            for(int i = 0; i < cnt + go(midPre); i++){
                cout << s[i] ; 
            }
            for(int i = 0; i < cnt; i++){
                cout << s[n - cnt + i] ; 
            }
            cout << endl;
        }
        else{
            for(int i = 0; i < cnt; i++){
                cout << s[i] ; 
            }
            for(int i = 0; i < cnt + go(midSuf); i++){
                cout << s[n - (cnt + go(midSuf)) + i] ; 
            }
            cout << endl;
        }
    }
    else if ( go(naxPre) > go(naxSuf) ){
        for(int i = 0; i < go(naxPre); i++){
            cout << s[i] ; 
        }
        cout << endl;
    }
    else{
        for(int i = 0; i < go(naxSuf); i++){
            cout << s[n - go(naxSuf) + i] ; 
        }
        cout << endl;
    }
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ; 
    return 0; 
}