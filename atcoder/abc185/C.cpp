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
    int n ;
    cin >> n ;
    n -= 12 ;
    int x = n ;
    n += 11 ;
    vector<int> nom ;
    vector<int> den ;
    for(int i = 1; i <= n; i++){
    	nom.emplace_back(i) ;
    }
    for(int i = 1; i <= 11; i++){
    	den.emplace_back(i) ;
    }
    for(int i = 1; i <= x; i++){
    	den.emplace_back(i) ;
    }
    for(int &c : nom){
    	for(int &d : den){
    		int g = __gcd(c, d) ;
    		c /= g; 
    		d /= g;
    	}
    }
    debug() << imie(nom) ;
    debug() << imie(den) ;
    int bast = 1 ;
    for(int &c : nom){
    	bast *= c ;
    }
    int maqam = 1 ;
    for(int &c : den){
    	maqam *= c ;
    }
    int answer = bast / maqam ;
    cout << answer << endl;
    // 1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x ... x 49
    // ________________________________________
    // 1 x 2 x 3 x ... x 11 x 1 x 2 x ... x 38
    return 0; 
}
// equation = 49! / (38! * 11!)