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
	multiset<int> v[6] ; 
	for(int i=0;i<n;i++){
		int x ; 
		cin >> x ; 
		if ( x == 4 ) v[0].insert(i) ; 
		else if ( x == 8 ) v[1].insert(i) ; 
		else if ( x == 15 ) v[2].insert(i) ; 
		else if ( x == 16 ) v[3].insert(i) ; 
		else if ( x == 23 ) v[4].insert(i) ; 
		else if ( x == 42 ) v[5].insert(i) ; 
	}
	// we can remove all element to obtain good array
	// we need to take care of no 4s 
	int good = 0 ;
	for(int c : v[0]){
		int val = 0 ; 
		auto it = v[1].upper_bound(c) ; 
		if ( it == v[1].end() ){
			break; 
		}
		else {
			val = *it ; 
			v[1].erase(it) ; 
		}
		it = v[2].upper_bound(val) ; 
		if ( it == v[2].end() ){
			break; 
		}
		else {
			val = *it ; 
			v[2].erase(it) ; 
		}
		it = v[3].upper_bound(val) ; 
		if ( it == v[3].end() ){
			break; 
		}
		else {
			val = *it ; 
			v[3].erase(it) ; 
		}
		it = v[4].upper_bound(val) ; 
		if ( it == v[4].end() ){
			break; 
		}
		else {
			val = *it ; 
			v[4].erase(it) ; 
		}
		it = v[5].upper_bound(val) ; 
		if ( it == v[5].end() ){
			break; 
		}
		else {
			val = *it ; 
			v[5].erase(it) ; 
		}
		good++ ; 
	}
	if ( good == 0 ) {
		cout << n << endl;
	}
	else{
		cout << n - good*6 << endl;
	}
    return 0 ;
}
