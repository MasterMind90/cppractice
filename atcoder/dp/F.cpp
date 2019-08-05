#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const int MAXN = 3e3 + 10 ; 
string s , t ;
int n , m; 
int dp[MAXN][MAXN] ; 
int dfs(int x,int y){
	if ( x == n || y == m ) return 0 ; 
	if ( dp[x][y] != -1 ) return dp[x][y] ; 
	int choice1 = 0 ; 
	int choice2 = 0 ; 
	if ( s[x] == t[y] ) {
		choice1 = 1 + dfs(x+1,y+1) ; 
	}
	else{
		choice1 = dfs(x+1,y) ; 
		choice2 = dfs(x,y+1) ; 
	}
	return dp[x][y] = max(choice1,choice2) ; 
}
void build(int x,int y){
	if ( x == n || y == m ) return ; 
	int choice1 = 0 ; 
	int choice2 = 0 ; 
	int choice3 = 0 ; 
	if ( s[x] == t[y] ) {
		choice1 = 1 + dfs(x+1,y+1) ; 
	}
	else{
		choice2 = dfs(x+1,y) ; 
		choice3 = dfs(x,y+1) ; 
	}
	int optimal = dfs(x,y) ; 
	if ( optimal == choice2 ){
		build(x+1,y) ; 
	}
	else if ( optimal == choice3 ){
		build(x,y+1) ; 
	}
	else if ( optimal == choice1 ){
		cout << s[x] ; 
		build(x+1,y+1) ; 
	}
}
int main(){
    fastio
    memset(dp,-1,sizeof dp) ; 
    cin >> s >> t ; 
    n = (int) s.size() ; 
    m = (int) t.size() ; 
    dfs(0,0);
    build(0,0); 
    return 0 ;
}
