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

int main(){
    fastio
    int n ; 
    cin >> n ; 
    string s ; 
    cin >> s ; 
    vector<int> sumW(n+1),sumE(n+1) ; 
    for(int i=0;i<n;i++){
    	if ( s[i] == 'W' ) sumW[i+1] = 1; 
    	else sumE[i+1] = 1 ; 
    }
    for(int i=1;i<=n;i++){
    	sumW[i] += sumW[i-1];
    	sumE[i] += sumE[i-1];
    }
    debug() << imie(sumW) ; 
    debug() << imie(sumE) ; 
    int ans = 1e9 + 10 ; 
    for(int i=0;i<n;i++){
    	int cntW = sumW[i] ; 
    	int cntE = sumE[n] - sumE[i+1] ; 
    	ans = min(ans,cntW+cntE) ; 
    }
    cout << ans << endl;
    return 0 ;
}
