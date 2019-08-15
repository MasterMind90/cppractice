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
const int MAXN = 150000 + 5 ;
int main(){
    fastio
    int n ; 
    cin >> n ; 
    vector<int> v(n) ; 
    vector<int> used(MAXN);
    for(int i=0;i<n;i++){
    	cin >> v[i] ; 
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
    	int t = max(1,v[i]-1) ;
    	if ( !used[t] ) used[t] = true ;
    	else if ( !used[t+1] ) used[t+1] = true ;
    	else used[t+2] = true ;
    }
    int ans = 0 ;
    for(int i=1;i<MAXN;i++) 
    	ans += used[i];
    cout << ans << endl;
    return 0 ;
}
