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
	cin >> n >> q ; 
	vector<ll> v(n) ; 
	vector<ll> sum(n+1) ; 
	sum[0] = 0 ; 
	for(int i=0;i<n;i++){
		cin >> v[i] ; 
		sum[i+1] = sum[i] + v[i] ; 
	}
	debug() << imie(sum) ; 
	vector<ll> arrow(q) ; 
	int cur = 1 ; 
	ll leftover = 0 ; 
	for(int i=0;i<q;i++){
		cin >> arrow[i] ; 
		int L = cur , R = n ; 
		int ans = -1 ; 
		while(L<=R){
			int mid = L + (R-L)/2; 
			if ( sum[mid] - sum[cur-1] <= arrow[i]+leftover ){
				ans = mid ; 
				L = mid + 1 ;
			}
			else R = mid - 1 ;
		}
		if ( ans == -1 ) {
			leftover += arrow[i] ; 
			debug() << imie(leftover) ; 
			cout << n - cur + 1 << endl;
			continue;
		}
		else if ( ans == n ){
			leftover = 0 ; 
			cur = 1 ; 
			cout << n << endl;
			continue ; 
		}
		else{
			leftover = leftover+arrow[i] - (sum[ans] - sum[cur-1]) ;
			debug() << imie(arrow[i]) imie(sum[ans]) imie(sum[cur-1]);
			cur = ans + 1 ; 
		}
		cout << n - ans << endl;
		debug() << imie(ans) ; 
	}
    return 0 ;
}
