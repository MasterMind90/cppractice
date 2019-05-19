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
int toInt(string x){
	stringstream ss ; 
	ss << x ; 
	int c ; 
	ss >> c ; 
	return c ; 
}
int main(){
	string s ; 
	cin >> s ; 
	string first = s.substr(0,2) ; 
	string second = s.substr(2) ; 
	stringstream ss ; 
	int x = toInt(first) ; 
	int y = toInt(second) ; 
	debug() << imie(first) imie(second) ; 
	debug() << imie(x) imie(y) ; 
	if ( x == 0 ) {
		if ( y <= 12 && y != 0 ){
			cout << "YYMM" << endl;
		}
		else cout << "NA" << endl;
	}
	else if ( y == 0 ){
		if ( x <= 12 && x != 0 ){
			cout << "MMYY" << endl;
		}
		else cout << "NA" << endl;
	}
	else if ( x > 12 && y > 12 ){
		cout << "NA" << endl;
	}
	else if ( x <= 12 && y <= 12 ){
		cout << "AMBIGUOUS" << endl;
	}
	else if ( x <= 12 ){
		cout << "MMYY" << endl;
	}
	else {
		cout << "YYMM" << endl;
	}
    return 0 ;
}
