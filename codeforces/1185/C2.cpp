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
		ll n , m ; 
		cin >> n >> m ; 
		vector<ll> t(n) ; 
		vector<ll> sum(n+1) ; 
		vector<ll> cnt(110) ; 
		sum[0] = 0 ; 
		for(ll i=0;i<n;i++){
			cin >> t[i] ; 
			sum[i+1] = sum[i] + t[i] ; 
			debug() << imie(sum) ; 
			if ( sum[i+1] <= m ){
				cout << 0 << ' ' ;
			}
			else{
				ll cur = sum[i+1] ; 
				debug() << imie(cur);
				ll v = t[i]; 
				debug() << imie(v) ; 
				ll res = 0 ; 
				for(ll j=100;j>=1;j--){
					if ( cnt[j] ){
						debug() << imie(j) imie(cnt[j]);
						ll L = 1 , R = cnt[j] ; 
						ll ans = -1 ; 
						while(L<=R){
							ll mid = L + (R-L) / 2 ; 
							if ( cur-mid*j  <= m ){
								debug() << imie(mid) ; 
								ans = mid ; 
								R = mid - 1 ; 
							}
							else L = mid + 1 ;
						}
						if ( ans == -1 ) {
							cur -= cnt[j]*j;
							res += cnt[j] ; 
						}
						else{
							res += ans ; 
							cout << res << ' ' ; 
							break;
						}
					}
				}
			}
			cnt[t[i]]++;
		}
		return 0 ;
	}