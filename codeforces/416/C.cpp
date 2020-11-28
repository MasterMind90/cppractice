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
int n ;
vector<pair<int,pair<int,int> > > v ;
int k ;
bool comp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
	if ( a.second.first > b.second.first ) return true ;
	return false ;
}
signed main(){
    fastio
    cin >> n ; 
    v = vector<pair<int,pair<int,int> > >(n) ;
    for(int i = 0; i < n; i++){
    	cin >> v[i].first >> v[i].second.first ;
    	v[i].second.second = i + 1 ; 
    }
    sort(v.begin(), v.end(), comp) ;
    cin >> k ; 
    multiset<pair<int,int> > ms ;
    for(int i = 0; i < k; i++){
    	int x ;
    	cin >> x ;
    	ms.emplace(x, i + 1) ;
    }
    vector<pair<int,int> > answer ;
    int ans = 0 ;
    for(int i = 0; i < n; i++){
    	auto a = v[i] ;
    	auto it = ms.lower_bound(make_pair(a.first, 0)) ;
    	if ( it == ms.end() ) continue ;
    	ans += a.second.first ;
    	answer.emplace_back(a.second.second, it->second) ;
    	ms.erase(it) ;
    }
    cout << (int) answer.size() << ' ' << ans << endl;
    for(auto &p : answer){
    	cout << p.first << ' ' << p.second << endl;
    }
    return 0; 
}