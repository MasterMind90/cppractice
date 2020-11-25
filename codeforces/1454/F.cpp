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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 
const ll INF = 1e9 + 10 ;
vector<int> v;
vector<pair<int,int> > T;
void build(int node, int start, int end){
    if ( start == end ){
        T[node].first = v[start] ;
        T[node].second = v[start] ;
    }
    else{
        int mid = (start + end) / 2;
        build(2 * node, start, mid) ;
        build(2 * node + 1, mid + 1, end);
        T[node].first = max(T[2 * node].first , T[2 * node + 1].first);
        T[node].second = min(T[2 * node].second , T[2 * node + 1].second);
    }
}
int queryMax(int node, int start, int end, int l, int r){
    if ( start > r || end < l ) return 0 ; 
    if ( start >= l && end <= r ){
        return T[node].first ; 
    }
    else{
        int mid = (start + end) / 2;
        int p1 = queryMax(2 * node, start, mid, l, r);
        int p2 = queryMax(2 * node + 1, mid + 1, end, l, r) ;
        return max(p1 , p2) ;
    }
}
int queryMin(int node, int start, int end, int l, int r){
    if ( start > r || end < l ) return INF ; 
    if ( start >= l && end <= r ){
        return T[node].second ; 
    }
    else{
        int mid = (start + end) / 2;
        int p1 = queryMin(2 * node, start, mid, l, r);
        int p2 = queryMin(2 * node + 1, mid + 1, end, l, r) ;
        return min(p1 , p2) ;
    }
}
void solve(){
    int n ;
    cin >> n ;
    v = vector<int>(n) ;
    T = vector<pair<int,int> >(4 * n + 1) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    build(1, 0, n - 1) ;
    for(int i = 0; i < n; i++){
        int firstIndex = i ;
        int maxRange = queryMax(1, 0, n - 1, 0 , firstIndex) ;
        int L = firstIndex + 2, R = n - 1 ;
        while(L <= R){
            int mid = L + (R - L) / 2 ;
            int nixRange = queryMin(1, 0, n - 1, firstIndex + 1, mid - 1) ;
            int naxRange = queryMax(1, 0, n - 1, mid, n - 1) ; 
            if ( naxRange > maxRange ){
                L = mid + 1 ;
            }
            else if ( naxRange < maxRange ) {
                R = mid - 1 ;
            }
            else {
                if ( nixRange == maxRange ) {
                    int a = firstIndex + 1 ;
                    int b = mid - 1 - (firstIndex + 1) + 1 ; 
                    int c = n - 1 - mid + 1 ;
                    cout << "YES" << endl;
                    cout << a << ' ' << b << ' ' << c << endl;
                    return ;
                }
                else if ( nixRange < maxRange ) {
                    R = mid - 1 ;
                }
                else L = mid + 1 ;
            }
        }
    }
    cout << "NO" << endl;
}
int main(){
    fastio
    int t ;
    cin >> t ;
    while(t--) solve() ;
    return 0;
}
