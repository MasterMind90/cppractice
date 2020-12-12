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
int n , m ;
int F(int x){
	return x * (x + 1) / 2;
}
pair<int,int> go(int start, int ending){
	int L = start, R = ending ;
	int ans = -1 ;
	while(L <= R){
		int mid = L + (R - L) / 2 ;
		if ( F(mid) - F(start - 1) <= m ) {
			ans = mid ;
			L = mid + 1 ;
		}
		else R = mid - 1 ;
	}
	debug() << imie(ans) ;
	return make_pair(ans, F(ans) - F(start - 1))  ;
}
signed main(){
    fastio
    cin >> n >> m ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
    	cin >> v[i] ;
    }
    sort(v.begin(), v.end()) ;
    vector<pair<int,int> > answer ; 
    int total = 0 ;
    if ( v.front() != 1 ) {
    	pair<int,int> ans = go(1, v.front() - 1) ;
    	if ( ans.first != -1 ) {
    		total += ans.first ;
    		m -= ans.second ;
    		answer.emplace_back(1, ans.first) ;
    	}
    }
    for(int i = 1; i < n; i++){
    	int diff = v[i] - v[i - 1] ;
    	if ( diff > 1 ) {
    		pair<int,int> ans = go(v[i - 1] + 1, v[i] - 1) ;
    		if ( ans.first == -1 ) break ;
    		if ( ans.first != v[i] - 1 ) {
    			total += (ans.first - v[i - 1]) ;
    			m -= ans.second ;
    			answer.emplace_back(v[i - 1] + 1, ans.first) ;
    			break ;
    		}
    		else {
    			total += (ans.first - v[i - 1]) ;
    			m -= ans.second ;
    			answer.emplace_back(v[i - 1] + 1, ans.first) ;
    		}
    	}
    }
    if ( m > 0 ) {
    	if ( v.back() != (int)1e9 ) {
    		pair<int,int> ans = go(v.back() + 1, (int) 1e9) ;
    		if ( ans.first != -1 ) {
    			total += (ans.first - v.back()) ;
    			answer.emplace_back(v.back() + 1, ans.first) ;
    		}
    	}

    }
    cout << total << endl;
    for(auto &seg : answer){
    	for(int i = seg.first ; i <= seg.second; i++){
    		cout << i << ' ' ;
    	}
    }
    cout << endl;
    return 0; 
}