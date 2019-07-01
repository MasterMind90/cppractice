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
const int MAXN = 1e5 + 10 ;
int main(){
	string s , t ;
	cin >> s >> t ;
	int cnt1[26] ;
	memset(cnt1,0,sizeof cnt1) ;
	int cnt2[26] ;
	memset(cnt2,0,sizeof cnt2) ;
	for(char c : s){
		cnt1[c-'a']++;
	}
	for(char c : t){
		cnt2[c-'a']++;
	}
	int n = (int)s.size() ;

    for(int i=0;i<n;i++){
        if ( cnt1[s[i]-'a'] != cnt2[t[i]-'a'] ){
            cout << "No" << endl;
            return 0 ;
        }
    }
    cout << "Yes" << endl;



	return 0 ;
}
