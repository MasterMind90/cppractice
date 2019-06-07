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
	int n ; 
	cin >> n ; 
	vector<int> v(n) ; 
	map<int,int> cnt ; 
	for(int &x : v){
		cin >> x ; 
		cnt[x]++ ; 
	}
	int m ; 
	cin >> m ; 
	if ( m > n ) {
		cout << "NO" << endl;
		return 0 ; 
	}
	for(int i=0;i<m;i++){
		int x ; 
		cin >> x ; 
		int &c = cnt[x] ; 
		if ( c ){
			c-- ; 
		}
		else{
			cout << "NO" << endl;
			return 0 ; 
		}
	}
	cout << "YES" << endl;
    return 0 ;
}
