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
vector<int> v;
vector<int> T;
void build(int node, int start, int end){
    if ( start == end ){
        T[node] = v[start] ;
    }
    else{
        int mid = (start + end) / 2;
        build(2 * node, start, mid) ;
        build(2 * node + 1, mid + 1, end);
        T[node] = T[2 * node] + T[2 * node +1];
    }
}
int query(int node, int start, int end, int l, int r){
    if ( start > r || end < l ) return 0 ; 
    if ( start >= l && end <= r ){
        return T[node] ; 
    }
    else{
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r) ;
        return p1 + p2 ;
    }
}
void update(int node, int start, int end, int idx, int val){
    if ( start == end ){
        T[node] = val ; 
    }
    else{
        int mid = (start + end) / 2;
        if ( idx <= mid ) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val) ;
        T[node] = T[2 * node] + T[2 * node + 1] ;
    }
}

signed main(){
    fastio
    // aaaza
    // 01234
    // azaaa
    // 03124
    int n ; 
    cin >> n ;
    string s ;
    cin >> s ;
    deque<int> pos[26] ;
    for(int i = 0; i < n; i++){
        char &c = s[i] ;
        pos[c - 'a'].emplace_back(i) ;
    }
    string t = s ;
    reverse(t.begin(), t.end()) ;
    vector<int> x ;
    for(int i = 0; i < n; i++){
        if ( s[i] == t[i] ){
            char &c = s[i] ;
            x.emplace_back(pos[c - 'a'].front()) ; pos[c - 'a'].pop_front() ;
            continue ;
        }
        else{
            char &c = t[i] ;
            x.push_back(pos[c - 'a'].front()) ; pos[c - 'a'].pop_front() ;
        }
    }
    debug() << imie(x) ;
    v.resize(n) ;
    T.resize(4 * n) ;
    build(1, 0, n - 1) ;
    int ans = 0  ;
    for(int i = n - 1; i >= 0; i--){
        int cur = x[i] ;
        debug() << imie(cur) ;
        int val = query(1, 0 , n - 1, cur, cur) ;
        int sum = query(1, 0 , n - 1, 0, cur) ;
        debug() << imie(val) imie(sum) ;
        ans += sum ;
        update(1, 0, n - 1, cur, val + 1) ;
    }
    cout << ans << endl;
    return 0; 
}
//   01234
// s aaaza
// t azaaa

// abc
// cba

// icpcsguru

// urugscpci


// abc
// cba


// 210
