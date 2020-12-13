#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
~debug() { cerr << '\n'; }
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    string t ;
    cin >> t ;
    int m = (int) t.size() ;
    int extra = 0 ;
    for(char &c : s) extra += c == '?' ;
    vector<int> cnt1(26) ;
	vector<int> cnt2(26) ;
	for(char &c : s ) if ( c != '?' ) cnt1[c - 'a']++ ;
	for(char &c : t) cnt2[c - 'a']++ ;
	int L = 0, R = (int)1e6 ;
	int answer = -1;
	while(L <= R){
		int mid = L + (R - L) / 2 ;
		int cur = extra ;
		bool ok = true ;
		for(int i = 0; i < 26; i++){
			if ( cnt2[i] != 0 ) {
				int need = mid * cnt2[i] ;
				if ( cnt1[i] >= need ) continue ;
				cur -= need - cnt1[i] ;
				if ( cur < 0 ) {
					ok = false ;
					break ;
				}
			}
		}
		if ( ok ) {
			answer = mid ;
			L = mid + 1 ;
		}
		else R = mid - 1 ;
	}
	if ( answer == -1 ) {
		for(char &c : s){
			if ( c == '?' ) c = 'z' ;
		}
		cout << s << endl;
		return 0 ;
	}
	vector<char> ans ;
	for(int i = 0; i < 26; i++){
		if ( cnt2[i] != 0 ) {
			int need = answer * cnt2[i] ;
			while(cnt1[i] < need){
				ans.push_back(i + 'a') ;
				cnt1[i]++ ;
				extra-- ;
			}
		}
	}
	while(extra) {
		ans.push_back('z') ;
		extra-- ;
	}
	for(char &c : s){
		if ( c == '?' ) {
			c = ans.back() ; ans.pop_back() ;
		}
	}
	cout << s << endl;
    return 0; 
}