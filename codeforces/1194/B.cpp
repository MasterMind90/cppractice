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

	int main(){
		fastio
		int q ; 
		cin >> q ;
		while(q--){
			int n , m ; 
			cin >> n >> m ; 
			char g[n+1][m+1] ; 
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cin >> g[i][j] ; 
				}
			}
			int right[n+2][m+2] ; 
			memset(right,0,sizeof right) ; 
			for(int i=1;i<=n;i++){
				for(int j=m;j>=1;j--){
					right[i][j] += right[i][j+1] + (g[i][j]=='.');
				}
			}
			int left[n+2][m+2] ; 
			memset(left,0,sizeof left) ; 
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					left[i][j] += left[i][j-1] + (g[i][j]=='.');
				}
			}
			int top[n+2][m+2] ; 
			memset(top,0,sizeof top) ; 
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					top[j][i] += top[j-1][i] + (g[j][i]=='.');
				}
			}
			int bottom[n+2][m+2] ; 
			memset(bottom,0,sizeof bottom) ; 
			for(int i=1;i<=m;i++){
				for(int j=n;j>=1;j--){
					bottom[j][i] += bottom[j+1][i] + (g[j][i]=='.');
				}
			}
			int nax = 1e9 + 10 ; 
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					nax = min(nax,left[i][j-1] + right[i][j+1] + bottom[i+1][j] + top[i-1][j] + (g[i][j] == '.'));
				}
			}
			cout << nax << endl;
		}
		return 0 ;
	}
