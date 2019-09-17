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
const int N = 110 ;
int n ; 
vector<int> day(N) ; 
// 0 means rest day
// 1 means contest day
// 2 means gym day
int dp[N][3];
int dfs(int x,int type){
    if ( x == n ) {
        return 0 ; 
    }
    if ( dp[x][type] != -1 ) return dp[x][type] ;
    debug() << imie(x) imie(type) ;
    int ans = 0 ;
    if ( type == 0 ){
        if ( day[x] == 0 ) ans += dfs(x + 1, 0);
        else if ( day[x] == 1 ) ans += 1 + dfs(x + 1, 1);
        else if ( day[x] == 2 ) ans += 1 + dfs(x + 1, 2);
        else{
            ans += max(1 + dfs(x + 1, 1), 1 + dfs(x + 1, 2) );
        }
    }
    else if ( type == 1 ){
        if ( day[x] == 0 || day[x] == 1 ) ans += dfs(x + 1, 0);
        else if ( day[x] == 2 || day[x] == 3 ) ans += 1 + dfs(x + 1, 2);
    }
    else {
        if ( day[x] == 0 || day[x] == 2 ) ans += dfs(x + 1, 0);
        else if ( day[x] == 1 || day[x] == 3) ans += 1 + dfs(x + 1, 1);
    }
    return dp[x][type] = ans; 
}
int main(){
    memset(dp, -1, sizeof dp);
	cin >> n ; 
	for(int i=0;i<n;i++){
		cin >> day[i] ; 
	}
    int ans = n - dfs(0, 0);
    cout << ans << endl;
    return 0 ;
}
