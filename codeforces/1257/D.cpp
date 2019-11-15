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
const int MOD = 1e9 + 7 ;
const int N = 1e5 + 10 ;
const int INF = 1e9 + 10 ; 
int n;
vector<int> T;
vector<int> a ; 
void build(int node, int start, int end){
    if ( start == end ){
        T[node] = a[start] ; 
    }
    else{
        int mid = (start + end) / 2 ;
        build(2 * node, start, mid) ;
        build(2 * node + 1, mid + 1, end) ; 
        T[node] = max(T[2 * node], T[2 * node + 1]);
    }
}
int query(int node, int start, int end, int l, int r){
    if ( start > r || end < l ) return -INF ; 
    if ( start >= l && end <= r ){
        return T[node] ; 
    }
    else{
        int mid = (start + end) / 2 ;
        int p1 = query(2 * node, start, mid, l , r) ; 
        int p2 = query(2 * node + 1, mid + 1, end, l , r) ; 
        return max(p1, p2) ;
    }
}
void solve(){
    cin >> n ; 
    T.resize(4 * n + 1) ; 
    a.resize(n) ; 
    int nax = 0 ; 
    for(int i = 0; i < n; i++){
        cin >> a[i] ; 
        nax = max(nax, a[i]) ; 
    }
    build(1, 0, n - 1) ; 
    int m ; 
    cin >> m ;
    int nax2 = 0 ; 
    vector<pair<int,int> > hero(m) ; 
    vector<int> end(n + 1) ; 
    for(int i = 0; i < m; i++){
        cin >> hero[i].first >> hero[i].second ;
        end[hero[i].second] = max(end[hero[i].second], hero[i].first) ; 
        nax2 = max(nax2, hero[i].first) ; 
    }
    if ( nax2 < nax ) {
        cout << -1 << endl ; 
        return ; 
    }
    for(int i = n - 1; i >= 0; i--){
        end[i] = max(end[i], end[i + 1]) ; 
    }
    int days = 0 ; 
    for(int i = 0; i < n;){
        int L = i , R = n - 1;
        int ans = -1; 
        while(L <= R){
            int mid = L + (R - L) / 2;
            int max = query(1, 0, n - 1, i, mid);
            int len = mid - i + 1 ;
            if ( end[len] >= max ) {
                ans = mid ; 
                L = mid + 1;
            }
            else R = mid - 1;
        }
        days++; 
        i = ans + 1;
    }
    cout << days << endl;
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