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
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;

int main(){
    fastio
    int n , k ; 
    cin >> n >> k ; 
    vector<int> v(n) ; 
    for(int &x : v){
    	cin >> x ; 
    }
    int extra = k - n / 2 ; 
    extra = extra * 2 ; 
    if ( n % 2 ) extra--;
    int nax = v[n-1] ; 
    debug() << imie(extra) imie(nax) ; 
    for(int i=0,j=n-extra-1;i<=j;i++,j--){
    	if ( i == j ) {
    		nax = max(nax,v[i]) ; 
    		continue ; 
    	}
    	debug() << imie(v[i]) imie(v[j]) imie(v[i]+v[j]); 
    	nax = max(nax,v[i]+v[j]) ; 
    }
    cout << nax << endl;
    return 0 ;
}

