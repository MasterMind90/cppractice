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
const ll MAXN = 1e5 + 10 ; 
ll n ; 
vector<vector<ll> > activity ; 
ll dp[MAXN][3] ; 
ll dfs(ll day,ll act){
	if ( day == n-1 ){
		return activity[day][act] ; 
	}
	if ( dp[day][act] ) return dp[day][act] ; 
	ll val = 0 ; 
	for(ll i=0;i<3;i++){
		if ( i != act ){
			val = max(val, activity[day][act] + dfs(day+1,i) ) ; 
		}
	}
	dp[day][act] = val  ; 
	return val ; 
}
int main(){
	cin >> n ; 
	activity.resize(n) ; 
	for(ll i=0;i<n;i++){
		for(ll j=0;j<3;j++){
			ll x ;
			cin >> x ; 
			activity[i].push_back(x) ; 
		}
	}
	cout << max({dfs(0,0),dfs(0,1),dfs(0,2)}) << endl;
	return 0 ;
}
