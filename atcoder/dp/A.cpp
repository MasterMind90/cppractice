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
typedef long long ll;
int n ; 
vector<ll> v ; 
vector<ll> dp ; 
int dfs(int x){
	if ( x == n-1 ) return 0 ; 
	if ( dp[x] != 1e9 ) return dp[x] ; 
	int first = 1e9 ; 
	if ( x < n-2 )
		first = abs(v[x]-v[x+2]) + dfs(x+2) ; 
	int second = 1e9 ; 
	if ( x < n-1 )
		second = abs(v[x]-v[x+1]) + dfs(x+1) ; 
	dp[x] = min(second,first) ; 
	return dp[x] ; 
}
int main(){
	cin >> n ; 
	v.resize(n) ; 
	dp.resize(n+2,1e9) ; 
	for(int i=0;i<n;i++){
		cin >> v[i] ; 
	}
	cout << dfs(0) << endl;
    return 0 ;
}
