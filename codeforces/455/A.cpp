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

using ll = long long ;
const int MAXN = 1e5 + 10 ;
vector<int> cnt(MAXN) ;
ll dp[MAXN] ;
ll dfs(int x){
	if ( x >= MAXN ) return 0 ;
	if ( dp[x] != -1 ) return dp[x] ;
	ll choice1 = dfs(x+1) ;
	ll choice2 = 1LL*x*cnt[x] + dfs(x+2) ;
	dp[x] = max(choice1,choice2) ;
	return dp[x] ;
}
int main(){
    memset(dp,-1,sizeof dp);
	int n ;
	cin >> n ;
	for(int i=0;i<n;i++){
		int x ;
		cin >> x ;
		cnt[x]++ ;
	}
	cout << dfs(0) << endl;
	return 0 ;
}
