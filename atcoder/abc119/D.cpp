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
	ll n , m , q ;
	cin >> n >> m >> q ;
	vector<ll> s(n) , t(m);
	for(ll i=0;i<n;i++){
		cin >> s[i] ;
	}
	for(ll i=0;i<m;i++){
		cin >> t[i] ;
	}
	while(q--){
		ll x ;
		cin >> x ;
		ll index = lower_bound(s.begin(),s.end(),x) - s.begin() ;
		vector<ll> first,second ;
		if ( index == n ) first.push_back(s[index-1]) ;
		else if ( index == 0 ) first.push_back(s[index]) ;
		else {
			first.push_back(s[index]) ;
			first.push_back(s[index-1]) ;
		}
		index = lower_bound(t.begin(),t.end(),x) - t.begin() ;
		if ( index == m ) second.push_back(t[index-1]) ;
		else if ( index == 0 ) second.push_back(t[index]) ;
		else {
			second.push_back(t[index]) ;
			second.push_back(t[index-1]) ;
		}
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
		debug() << imie(first) ;
		debug() << imie(second) ;
		ll ans = 1e18 ;
		for(ll i=0;i<(ll)first.size();i++){
            for(ll j=0;j<(ll)second.size();j++){
                if ( first[i] >= x && second[j] >= x ) ans = min(ans,max(first[i],second[j])-x);
                else if ( first[i] <= x && second[j] <= x ) ans = min(ans,x-min(first[i],second[j]));
                else{
                    if ( abs(first[i]-x) <= abs(second[j]-x) ){
                        ll ff = abs(first[i]-x) ;
                        ll ss = abs(second[j]-x) ;
                        ans = min(ans,2*ff+ss) ;
                    }
                    else{
                        ll ff = abs(first[i]-x) ;
                        ll ss = abs(second[j]-x) ;
                        ans = min(ans,2*ss+ff) ;
                    }
                }
            }
		}
		cout << ans << endl;
	}
    return 0 ;
}
