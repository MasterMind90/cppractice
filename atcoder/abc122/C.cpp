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
	int n , q ; 
	cin >> n >> q; 
	string s ; 
	cin >> s ; 
	vector<int> sum(n+1,0) ; 
	for(int i=0;i<=(int)s.size()-2;i++){
		string tmp = s.substr(i,2) ; 
		if ( tmp == "AC" ){
			sum[i+2-1] = 1 ; 
		}
		debug() << imie(sum) ; 
	}
	for(int i=1;i<(int)sum.size();i++){
		sum[i] += sum[i-1] ; 
	}
	debug() << imie(sum) ; 
	while(q--){
		int l , r ; 
		cin >> l >> r ; 
		l--,r--;
		debug() << imie(l) imie(sum[l]); 
		debug() << imie(r) imie(sum[r]); 
		cout << sum[r] - sum[l] << endl;
	}
    return 0 ;
}
