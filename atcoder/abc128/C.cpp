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
const int MAXN = 10 ; 
int bulb[MAXN][MAXN] ; 
int main(){
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			bulb[i][j] = 0 ; 
		}
	}
	int n , m ; 
	cin >> n >> m ; 
	for(int i=0;i<m;i++){
		int k ;
		cin >> k ; 
		for(int j=0;j<k;j++){
			int x ; 
			cin >> x ; 
			x--;
			bulb[i][x] = 1 ; 
		}
	}
	int p[MAXN] ; 
	for(int i=0;i<m;i++){
		cin >> p[i] ; 
	}
	int res = 0 ; 
	for(int mask = 0 ; mask < (1<<n) ; mask++ ){
		vector<int> state ; 
		for(int j=0;j<n;j++){
			if ( mask & (1 << j) ){
				state.push_back(j) ; 
			}
		}
		debug() << imie(state) ; 
		int ans = 0 ; 
		for(int i=0;i<m;i++){
			int cnt = 0 ; 
			for(int c : state){
				if ( bulb[i][c] ){
					cnt++ ; 
				}
			}
			if ( cnt % 2 == p[i] ) ans++ ; 
		}
		if ( ans == m ) res++ ; 
	}
	cout << res << endl;
	return 0 ;
}
