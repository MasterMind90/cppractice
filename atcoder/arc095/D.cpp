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

int main(){
	int n ;
	cin >> n ;
	vector<int> v(n) ;
	for(int &x : v){
		cin >> x ;
	}
	sort(v.begin(),v.end()) ;
	debug() << imie(v) ;
	int nax = v[n-1] ;
    int index = lower_bound(v.begin(),v.end(),nax/2) - v.begin();
    if ( v[index] == nax/2 || v[index] == nax/2+1 ){
    	cout << nax << ' ' << v[index] << endl;
    }
    else {
    	if ( v[index-1] >= nax-v[index] ){
    		cout << nax << ' ' << v[index-1] << endl;
    	}
    	else cout << nax << ' ' << v[index] << endl;
    }
    return 0 ;
}
