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
	ll x , y , z , k ; 
	cin >> x >> y >> z >> k ; 
	priority_queue<ll> q ; 
	vector<ll> a(x) , b(y) , c(z) ; 
	for(ll &g: a){
		cin >> g ; 
	}
	for(ll &g: b){
		cin >> g ; 
	}
	for(ll &g: c){
		cin >> g ; 
	}
	vector<ll> ans ; 
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			ans.push_back(a[i]+b[j]);
		}
	}
	sort(ans.rbegin(),ans.rend());
	debug() << imie(ans) ; 
	sort(c.rbegin(),c.rend());
	debug() << imie(c) ; 
	vector<ll> res ; 
	for(int i=0;i<min(k,(ll)ans.size());i++){
		for(int j=0;j<z;j++){
			res.push_back(ans[i]+c[j]);
		}
	}
	debug() << imie(res) ; 
	sort(res.rbegin(),res.rend());

	for(int i=0;i<min(k,x*y*z);i++){
		cout << res[i] << endl;
	}
	return 0 ;
}
