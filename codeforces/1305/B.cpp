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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    string s ;
    cin >> s ; 
    int n = (int) s.size() ; 
    deque<int> open , close ;
    for(int i = 0; i < n; i++){
        if ( s[i] == '(' ) open.push_back(i) ; 
        else close.push_back(i) ; 
    }
    vector<int> ans ; 
    bool ok = false ;
    bool flag = false ;
    while(open.size() && close.size()){
        ok = false ;
        if (open.front() < close.back() ){
            ok = true ; 
            flag = true ; 
            ans.push_back(open.front());
            ans.push_back(close.back());
            open.pop_front() ; 
            close.pop_back() ;
        }
        if ( ok ) continue ; 
        break;
    }
    if ( !flag ){
        cout << 0 << endl;
    }
    else{
        sort(ans.begin(), ans.end()) ;
        cout << 1 << endl;
        cout << ans.size() << endl;
        for(int c : ans){
            cout << c + 1 << ' ' ; 
        }
        cout << endl;
    }
    return 0; 
}