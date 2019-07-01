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
    int n , X ; 
    cin >> n >> X ; 
    vector<int> v(n) ; 
    for(int &x : v){
    	cin >> x ; 
    }
    if ( n == 1 ){
    	cout << abs(X-v[0]) << endl;
    	return 0 ; 
    }
    sort(v.begin(),v.end());
    debug() << imie(v) ; 
    vector<int> diff ; 
    for(int i=1;i<n;i++){
    	diff.push_back(v[i]-v[i-1]) ; 
    }
    debug() << imie(diff) ; 
    int d = v[1] - v[0] ; 
    vector<int> divisors ; 
    for(int i=1;i<=sqrt(d);i++){
    	if ( d % i == 0 ){
    		if ( d / i == i ) divisors.push_back(i) ; 
    		else {
    			divisors.push_back(d/i) ; 
    			divisors.push_back(i) ; 
    		}
    	}
    }
    sort(divisors.begin(),divisors.end()) ; 
    reverse(divisors.begin(),divisors.end()) ; 
    debug() << imie(d) ; 
    for(int div : divisors){
    	if ( d%div == 0 && abs(X-v[0]) % div == 0 ){
    		bool flag = true ; 
    		for(int c : diff){
    			if ( c % div != 0 ) {
    				flag = false ; 
    				break ; 
    			}
    		}
    		if ( flag ) {
    			cout << div << endl;
    			return 0 ; 
    		}
    	}
    }
    return 0 ;
}
