#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
void solve(){
	int n , k ; 
	cin >> n >> k ; 
	vector<ll> v(n) ; 
	vector<ll> sum(n+1) ; 
	for(int i=0;i<n;i++){
		cin >> v[i] ; 
		sum[i+1] = sum[i] + v[i] ; 
	}
	vector<int> ans ; 
	int last = 0; 
	for(int i=1;i<n;i++){
		if ( (sum[i] - sum[last]) % 2 == 1 && k > 1 ){
			ans.push_back(i) ; 
			last = i ; 
			k--;
		}
	}
	if ( k == 1 ){
		if ( (sum[n] - sum[last]) % 2 == 1 ){
			ans.push_back(n) ; 
			cout << "YES" << endl;
			for(int &c : ans){
				cout << c << ' '  ; 
			}
			cout << endl;
			return ;
		}
	}
	cout << "NO" << endl;
}
int main(){
    fastio
    int t ;
    cin >> t ; 
    while(t--){
    	solve() ; 
    }

    return 0 ;
}
