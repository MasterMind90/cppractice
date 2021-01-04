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
// #define int long long
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
const ll INF = 1e10 + 10 ;
vector<array<int, 3> > v;
vector<pair<int,int> > T;
void build(int node, int start, int end){
    if ( start == end ){
        T[node].first = v[start][1] ;
        T[node].second = v[start][2] ;
        // debug() << imie(T[node]) ;
    }
    else{
        int mid = (start + end) / 2;
        build(2 * node, start, mid) ;
        build(2 * node + 1, mid + 1, end);
        if ( T[2 * node].first < T[2 * node + 1].first ) {
	        T[node].first = min(T[2 * node].first,T[2 * node +1].first);
	        T[node].second = T[2 * node].second ;
        }
        else {
	        T[node].first = min(T[2 * node].first,T[2 * node +1].first);
	        T[node].second = T[2 * node + 1].second ;
        }

    }
}
pair<int,int> query(int node, int start, int end, int l, int r){
	// debug() << imie(start) imie(end) ;
    if ( start > r || end < l ) return make_pair(1e9 + 10, 1e9 + 10) ; 
    if ( start >= l && end <= r ){
        return T[node] ; 
    }
    else{
        int mid = (start + end) / 2;
        // debug() << imie(mid) ;
        pair<int,int> p1 = query(2 * node, start, mid, l, r);
        pair<int,int> p2 = query(2 * node + 1, mid + 1, end, l, r) ;
        // debug() << imie(p1) imie(p2) ;
        if ( p1.first < p2.first ) {
        	return p1 ;
        }
        else return p2 ;
    }
}
// int main(){
//     fastio
//     int n , q ; 
//     cin >> n >> q ;
//     v.resize(n) ;
//     T.resize(4 * n) ;
//     for(int &x : v){
//         cin >> x ; 
//     }
//     build(1, 0, n - 1) ;
//     while(q--){
//         int x , y ; 
//         cin >> x >> y ; 
//         x--, y--;
//         cout << query(1, 0, n - 1, x, y) << endl;
//     }
//     return 0;
// }
void solve(){
	int n ;
	cin >> n ;
	vector<int> a(n) , b(n) ;
	// vector<array<int, 3> > v(n) ;
	v = vector<array<int, 3> >(n) ;
	T = vector<pair<int,int> > (4 * n + 10) ;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] ;
		if ( b[i] > a[i] ) swap(a[i], b[i]) ;
		v[i][0] = a[i] ;
		v[i][1] = b[i] ;
		v[i][2] = i ;
	}
	sort(v.rbegin(), v.rend()) ;
	build(1, 0, n - 1) ;
	debug() << imie(v) ;
	debug() << imie(query(1, 0, n - 1, 3, 3)) ;
	vector<int> ans(n, -1) ;
	for(int i = 0; i < n; i++){
		int curA = v[i][0] ;
		int curB = v[i][1] ;
		int curId = v[i][2] ;
		int answer = -1;
		int L = i + 1, R = n - 1 ;
		while(L <= R){
			int mid = L + (R - L) / 2 ;
			if ( v[mid][0] < curA ) {
				answer = mid ;
				R = mid - 1 ;
			}
			else L = mid + 1 ;
		}
		if ( answer != -1 ) {
			debug() << imie(curA) imie(curB) imie(curId) ;
			debug() << imie(answer) ;
			pair<int,int> nix = query(1, 0, n - 1, answer, n - 1) ;
			debug() << imie(nix) ;
			if ( nix.first < curB ) {
				ans[curId] = nix.second ;
			}
		}
	}
	for(int &c : ans){
		if ( c == -1 ) cout << -1 << ' ' ;
		else cout << c + 1 << ' ' ;
	}
	cout << endl;
}
signed main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0; 
}
