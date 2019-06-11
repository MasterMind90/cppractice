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

int main(){
	int n , m ; 
	cin >> n >> m ;
	char grid[n][m] ; 
	bool vis[n][m] ; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grid[i][j] ; 
			vis[i][j] = false ; 
		}
	}
	int ans = 0 ; 
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if ( grid[i][j] == '*' && !vis[i][j] ){
				if ( grid[i-1][j] == '*' && grid[i+1][j] == '*' && grid[i][j-1] == '*' && grid[i][j+1] == '*' ){
					vis[i][j] = true ; 
					int left = 0 ; 
					for(int c=j-1;c>=0;c--){
						if ( grid[i][c] == '*' ) left++,vis[i][c] = true ; 
						else break ; 
					}
					int right = 0 ; 
					for(int c=j+1;c<m;c++){
						if ( grid[i][c] == '*' ) right++,vis[i][c] = true ; 
						else break ; 
					}
					int up =  0 ; 
					for(int c=i-1;c>=0;c--){
						if ( grid[c][j] == '*' ) up++, vis[c][j] = true ; 
						else break ; 
					}
					int down =  0 ; 
					for(int c=i+1;c<n;c++){
						if ( grid[c][j] == '*' ) down++ ,vis[c][j] = true; 
						else break ; 
					}
					debug() << imie(left) imie(right) imie(up) imie(down) ;
					if ( left && right && up && down ) ans++ ; 
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if ( grid[i][j] == '*' && !vis[i][j] ){
				cout << "NO" << endl;
				return 0 ; 
			}
		}
	}
	if ( ans == 1 ) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0 ;
}
