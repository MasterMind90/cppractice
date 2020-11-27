#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

signed main(){
    fastio;
    int k ; 
    cin >> k ; 
    string s ;
    cin >> s ;
    int n = (int) s.size() ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
    	v[i] = s[i] == '0' ? 0 : 1 ;
    }
    vector<int> sum(n + 1) ;
    for(int i = 0; i < n; i++){
    	sum[i + 1] = sum[i] + v[i] ; 
    }
    int answer = 0;
    for(int i = 1; i <= n; i++){
    	int L = 0 , R = i - 1 ;
    	int b = -1 ;
    	while(L <= R){
    		int mid = L + (R - L) / 2 ;
    		if ( sum[i] - sum[mid] == k ) {
    			b = mid ; 
    			L = mid + 1 ;
    		}
    		else if ( sum[i] - sum[mid] > k ) {
    			L = mid + 1 ;
    		}
    		else R = mid - 1 ;
    	}
    	int a = -1 ;
    	L = 0, R = i - 1 ;
    	while(L <= R){
    		int mid = L + (R - L) / 2 ;
    		if ( sum[i] - sum[mid] == k ) {
    			a = mid ; 
    			R = mid - 1 ;
    		}
    		else if ( sum[i] - sum[mid] > k ) {
    			L = mid + 1 ;
    		}
    		else R = mid - 1 ;
    	}
    	if ( a != -1 && b != -1 ) answer += b - a + 1 ;
    	debug() << imie(b) imie(a) ;
    }
    cout << answer << endl;
    return 0 ;
}
