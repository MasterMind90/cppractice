#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
vector<pair<int,int> > v;
vector<int> T;
vector<int> lazy ; 
void build(int node, int start, int end){
    if ( start == end ){
        T[node] = v[start].second ; 
    }
    else{
        int mid = (start + end) / 2;
        build(2 * node, start, mid) ; 
        build(2 * node + 1, mid + 1, end) ;
        T[node] = T[2 * node] + T[2 * node + 1] ;
    }
}
void update(int node, int start, int end, int l, int r,int val){
    if ( start > r || end < l ) return;
    if ( start >= l && end <= r ){
        lazy[node] += val ; 
    }
    else{
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val) ; 
        update(2 * node + 1, mid + 1, end, l, r , val) ; 
    }
}
int query(int node,int start, int end,int l, int r){
    if ( start > r || end < l ) return 0 ;
    if ( lazy[node] != 0 ){
        T[node] += lazy[node];
        if ( start != end ){
            lazy[2 * node] += lazy[node] ;
            lazy[2 * node + 1] += lazy[node] ;
        }
        lazy[node] = 0 ; 
    }
    if ( start >= l && end <= r ){
        return T[node] ; 
    }
    else{
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l , r) ;
        int p2 = query(2 * node + 1, mid + 1, end, l , r) ;
        return p1 + p2 ; 
    }
}
signed main(){
    fastio
    int n , d , a ; 
    cin >> n >> d >> a ;
    v.resize(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second ;
    }
    sort(v.begin(), v.end()) ;
    T.resize(4 * n) ;
    lazy.resize(4 * n) ;
    build(1, 0, n - 1);
    int sum = 0 ; 
    for(int i = 0; i < n; i++){
        //int H = v[i].second ;
        int H = query(1, 0, n - 1, i, i) ;
        if ( H > 0 ){
            int curx = v[i].first ;
            int L = i , R = n - 1;
            int ans = -1 ;
            while(L <= R){
                int mid = L + (R - L) / 2 ;
                if ( v[mid].first <= curx + 2 * d ){
                    ans = mid ; 
                    L = mid + 1 ;
                }
                else R = mid - 1;
            }
            assert(ans != -1) ;
            int val = (H + a - 1) / a ;
            debug() << imie(H) imie(val) imie(i) imie(ans);
            sum += val ;
            val = val * a ;
            update(1, 0, n - 1, i, ans, -val);
            // for(int j = i; j <= ans; j++){
            //     v[j].second -= val ;
            // }
        }
    }
    cout << sum << endl;
    return 0; 
}