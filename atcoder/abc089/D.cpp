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
    int n , m , d ; 
    cin >> n >> m >> d ; 
    pair<int,int> pos[n*m+1] ; 
    int grid[n][m] ; 
    int mem[n*m+1] ; 
    memset(mem,-1,sizeof mem) ; 
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> grid[i][j] ; 
    		pos[grid[i][j]] = { i , j } ; 
    	}
    }
    for(int i=n*m;i>=1;i--){
    	if ( mem[i] == -1 ){
    		debug() << imie(i) ; 
    		mem[i] = 0 ; 
    		int previous = i ; 
    		int start = i-d; 
    		while(start >= 1){
    			debug() << imie(previous) imie(start) ; 
    			auto pre = pos[previous] ; 
    			auto next = pos[start] ; 
    			debug() << imie(pre) imie(next) ; 
    			mem[start] = mem[previous] + abs(pre.first - next.first) + abs(pre.second - next.second) ;
    			debug() << imie(mem[start]) ; 
    			previous = start ; 
    			start -= d ; 
    		}
    	}
    }
    int t ; 
    cin >> t ; 
    while(t--){
    	int l , r ; 
    	cin >> l >> r ; 
    	debug() << imie(l) imie(r) ; 
    	cout << mem[l] - mem[r] << endl;
    }
    return 0 ;
}
